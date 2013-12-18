//
//  solver.h
//  unblockme_solver
//
//  Created by Alexander G Anderson on 12/16/13.
//  Copyright (c) 2013 Alexander G Anderson. All rights reserved.
//

/*
 Solver - Solves Unblock Me game
 
 *************
 *** INTRO ***
 *************
 
 Uses a modified Breadth First Search through the graph of possible game
    states
 
 
 Unblock Me is a game where blocks are placed horizontally and vertically
    on a grid. H-blocks move left to right and V-blocks move up and down.
 
 The following board is hard coded into this class:
 
 
  ---> i
 |
 |
 V
 j
 
 7 -1  8  6  6  6
 7 -1  8  9 -1 -1
 7  0  0  9 -1 10
 1  1  2  2 -1 10
 3  3  4  4 -1 10
 5  5 -1 -1 -1 -1
 
 (The hardest puzzle in the Unblock Me - Free app)
 
 eg. the three 7's form a vertical block
    -1 means that the square is empty
 
 The goal of the game is to rearrange the blocks so that block 0 can be
    moved all the way to the right of the board
 
 **************
 ***SOLUTION***
 **************
 
 The algorithm finds a possible sequence of moves that solve the puzzle.
 
 The game states and transitions between them naturally form a potentially
    large graph with many loops. We build the graph as we search through
    potential game states.
 
 We use two data structures to accomplish this task:
 
 vector<Node> nodes = Nodes
 Node = game state and game states obtainable from moving one block
 CBoardMap = ordered map containing game states and their locations
    memory
 
 Sketch of algorithm
 
 1. Create a node for the initial game state and add it to both data
    structures. Set i = 0.
 2. For the ith game state, try to move each block 1 space up/down or
    left/right
 3. For each of these game states, check if they have been visted
        CBoardMap facilitates this check in O(lg(n_boards)) time
 4. If a game state is new, push_back a node for that state, and
    add necessary parent/child references
 5. Increase i, and go back to 2
 6. The algorithm stops when block 0 reaches the right
 
 The solution is found by backtracing through the graph.
 
 */


#ifndef __unblockme_solver__solver__
#define __unblockme_solver__solver__

#include <iostream>
#include <vector>
#include "Node.h"
#include "e_board.h"
#include <map>

// User defined comparator for CBoards that allows them to be stored
//  efficiently in a map (look up and insertion in O(lg(Map.size()))
struct CBoardCompare {
    bool operator()(const CBoard& c1, const CBoard& c2) const {
        for (int i = 0; i < c1.bl_h.size(); ++i) {
            if(c1.bl_h[i].first != c2.bl_h[i].first)
                return c1.bl_h[i].first < c2.bl_h[i].first;
        }
        for (int i = 0; i < c1.bl_v.size(); ++i) {
            if (c1.bl_v[i].second != c2.bl_v[i].second)
                return c1.bl_v[i].second < c2.bl_v[i].second;
        }
        return false;
    }
};
// Map: key = CBoard c, value = location of c in memory (i.e.
// vector<Node> nodes
typedef std::map <CBoard, int, CBoardCompare> CBoardMap;

class Solver {
public:
    const char h = 0;
    const char v = 1;
    int L_X;
    int L_Y;
    // Ordered Map that contains (key,val) = (CBoard, location in nodes)
    CBoardMap visited_boards;
    // Vector containting Nodes - Node has CBoard and memory locations
    //  of parents and children of that node
    vector<Node> nodes;
    // Index of the end state
    int end_index;
    
    // Initializes First Node
    Solver();
    
    // Runs algorithm
    void run();
    
    // Finds the children of nodes[current_index], and calls
    //  create_child to make them
    void search_children(int current_index);
    
    // Creates a child node of a parent node = nodes[parent_index]
    //  child's CBoard is the same as the parents except the block
    //  of type (0=h, 1=v),
    void create_child(int parent_index, int block, int change, char type);
    
    
    
    
};


#endif /* defined(__unblockme_solver__solver__) */
