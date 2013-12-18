//
//  Node.h
//  unblockme_solver
//
//  Created by Alexander G Anderson on 12/16/13.
//  Copyright (c) 2013 Alexander G Anderson. All rights reserved.
//
/*
 
 Node - node in the graph of game states of the unblockme game
 
 As is the case with many discrete time - discrete space games, 
 the games states can be though of nodes in a graph and transitions
 from one game state to another are edges in the graph
 
 CBoard cb - stores game state in a compressed board
 
 For reasons more clearly described in solver.h, we divide the boards
 that are one move away from a Node into parent and children nodes.
 
 stores location in memory of parent nodes of this node
 vector<int> parents;
 
 Sample usage:
 
 vector<Node> nodes;
 Node n;
 CBoard& c = n.cb;
 **See c_board.h for initializing c**
 
 nodes.push_back(n);
 //n's location in memory is 0 as nodes[0]
 
 */
#ifndef __unblockme_solver__Node__
#define __unblockme_solver__Node__

#include <iostream>
#include <vector>
#include "c_board.h"

using std::vector;

class Node {
public:
    vector<int> parents;
    vector<int> children;
    CBoard cb;
    Node();
    void print();
    
};

#endif /* defined(__unblockme_solver__Node__) */
