//
//  c_board.cpp
//  unblockme_solver
//
//  Created by Alexander G Anderson on 12/16/13.
//  Copyright (c) 2013 Alexander G Anderson. All rights reserved.
//

#include "c_board.h"

CBoard::CBoard() {
    std::vector<loc> bl_h;
    std::vector<loc> bl_v;
}

void CBoard::add_bl_h(int i, int j, int size) {
    bl_h.push_back(std::make_pair(i,j));
    s_h.push_back(size);
}
void CBoard::add_bl_v(int i, int j, int size) {
    bl_v.push_back(std::make_pair(i,j));
    s_v.push_back(size);
}

void CBoard::print() {
    cout << "Left Corner of Horizontal Blocks" << endl;
    for (vector<loc>::iterator i = bl_h.begin(); i != bl_h.end(); ++i) {
        cout << "(" << i->first << ", " << i->second << "), ";
    }
    cout << endl;
    
    cout << "Top Corner of Vertical Blocks" << endl;
    for (vector<loc>::iterator i = bl_v.begin(); i != bl_v.end(); ++i) {
        cout << "(" << i->first << ", " << i->second << "), ";
    }
    cout << endl << endl;;
}

std::vector<int> CBoard::s_h; //block sizes for h blocks
std::vector<int> CBoard::s_v;