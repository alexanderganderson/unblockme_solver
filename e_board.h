//
//  e_board.h
//  unblockme_solver
//
//  Created by Alexander G Anderson on 12/16/13.
//  Copyright (c) 2013 Alexander G Anderson. All rights reserved.
//
/*
 EBoard = Expanded Board
 
 Takes in a CBoard and Fills an Array with the Blocks
 
 Sample usage:
 Cboard c;
 c.add_bl_h(0,0,2); // block zero
 c.add_bl_v(0,1,2); // block one
 
 EBoard::initialize_static(3,3);
 
 EBoard e = EBoard(c);
 e.print();
 
 outputs:
 
 0  0 -1
 1 -1 -1
 1 -1 -1
 
 (-1 = empty)
 
 
  ---> i,  L_X
 |
 |
 V
 j,  L_Y
 board[i][j] = number of block covering entry at column i, row j
 
 
 */


#ifndef __unblockme_solver__e_board__
#define __unblockme_solver__e_board__

#include <iostream>
#include <vector>
#include "c_board.h"

using std::cout;
using std::endl;
using std::vector;

class EBoard {
public:
    static int EMPTY;

    static int L_X; // Length of board in X - direction
    static int L_Y; // Length of board in Y - direction
    // board stored as a 2d array, with block number for each block
    vector<vector<int>> board;
    static void intialize_static(int L_X, int L_Y);
    
    // builds a L_X by L_Y grid and places blocks described by cb
    EBoard(CBoard cb);
    void print();
    
};


#endif /* defined(__unblockme_solver__e_board__) */
