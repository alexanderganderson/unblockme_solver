//
//  solver.cpp
//  unblockme_solver
//
//  Created by Alexander G Anderson on 12/16/13.
//  Copyright (c) 2013 Alexander G Anderson. All rights reserved.
//

#include "solver.h"



Solver::Solver() {
    // Initialize the starting board
    Node n_start = Node();
    L_X = 6;
    L_Y = 6;

    CBoard & start = n_start.cb;
    start.add_bl_h(1,2,2);
    start.add_bl_h(0,3,2);
    start.add_bl_h(2,3,2);
    start.add_bl_h(0,4,2);
    start.add_bl_h(2,4,2);
    start.add_bl_h(0,5,2);
    start.add_bl_h(3,0,3);
    
    start.add_bl_v(0,0,3);
    start.add_bl_v(2,0,2);
    start.add_bl_v(3,1,2);
    start.add_bl_v(5,2,3);
    
    EBoard::intialize_static(L_X, L_Y);
    end_index = -1;
    
    // Add start to data structures
    nodes.push_back(n_start);
    visited_boards[start]=0;
    
}

void Solver::run() {
    // Iterate through the boards until we find the solution or explore
    //  all boards.
    int i = 0;
    while (i < nodes.size()) {
        search_children(i);
        if (end_index != -1)
            break;
        ++i;
    }
    // Backtrace to get the solution
    vector<int> solution;
    int j = end_index;
    while (nodes[j].parents.size() != 0) {
        solution.push_back(j);
        j = nodes[j].parents[0];
    }
    solution.push_back(0);
    
    // Print the sequence of boards of the solution
    for (vector<int>::reverse_iterator i = solution.rbegin(); i != solution.rend(); ++i) {
        EBoard(nodes[*i].cb).print();
    }
    cout << endl;
    
}

/* create_child - Creates child of nodes[parent_index] where block of type
    type and index block is moved by change (= +1 or -1)
    If the game hasn't been visited yet, make a node for it and update
    the relevant parent/child references.
 */
void Solver::create_child(int parent_index, int block, int change, char type) {
    //create the indices for the new board
    Node n_c = Node();
    n_c.cb = nodes[parent_index].cb;
    
    if (type == 0)
        n_c.cb.bl_h[block].first += change;
    else
        n_c.cb.bl_v[block].second += change;
    
    //check if the state has been visited
    if(visited_boards.find(n_c.cb) == visited_boards.end()) {
        
        n_c.parents.push_back(parent_index);
        int new_index = (int) nodes.size();
        nodes[parent_index].children.push_back(new_index);
        visited_boards[n_c.cb]=new_index;
        if(n_c.cb.bl_h[0].first == L_X - n_c.cb.s_h[0])
            end_index=new_index;
        nodes.push_back(n_c);
    }
}

/*
 Finds children of nodes[current_index]
 */
void Solver::search_children(int current_index){
    Node& n = nodes[current_index];
    CBoard c = n.cb;
    EBoard e = EBoard(c);
    //Checks if each block can be moved left/right or up/down and then
    //  creates that node. 
    for(int i = 0; i < c.bl_h.size(); ++i) {
        int x = c.bl_h[i].first;
        int y = c.bl_h[i].second;
        if (x > 0)
            if(e.board[x - 1][y] == -1)
                 create_child(current_index, i, -1, h);
        if(x + c.s_h[i] < L_X)
            if(e.board[x + c.s_h[i]][y] == -1)
                create_child(current_index, i, 1, h);
    }
    
    for(int i = 0; i< c.bl_v.size(); ++i) {
        int x = c.bl_v[i].first;
        int y = c.bl_v[i].second;
        if (y > 0)
            if(e.board[x][y - 1] == -1)
                create_child(current_index, i, -1, v);
        if(y + c.s_v[i] < L_Y)
            if(e.board[x][y + c.s_v[i]] == -1)
                create_child(current_index, i, 1, v);
    }
    
}
