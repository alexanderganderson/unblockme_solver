//
//  c_board.h
//  unblockme_solver
//
//  Created by Alexander G Anderson on 12/16/13.
//  Copyright (c) 2013 Alexander G Anderson. All rights reserved.
//
/*
 CBoard = Compressed Board
 Blocks are stored with using the coordinates of their top left entry, and their size.
 
  ----> i (first coordinate)
 |
 |
 |
 V
 j (second coordinate)
 
 Sample usage:
 
 Cboard c;
 // Initialize the blocks and block lengths
 c.add_bl_h(0,0,2)
 c.add_bl_v(1,0,2)
 
 
 // After the first board, all subsequent boards are created by shifting blocks
 // continuing to use add_bl_h adds lengths to the static block size arrays
 Cboard c1 = c
 c1.bl_h.first += 1 or -1
 */

#ifndef __unblockme_solver__c_board__
#define __unblockme_solver__c_board__

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

// loc = location of upper right corner of the block
typedef std::pair<int,int> loc;

class CBoard {
public:
    // h = horizontal blocks
    // v = vertical blocks
    
    // s = size of the blocks
    static std::vector<int> s_h;
    static std::vector<int> s_v;
    
    // stores locations of blocks
    vector<loc> bl_h;
    vector<loc> bl_v;
    
    CBoard();
    // add a horizontal block
    void add_bl_h(int i, int j, int size);
    // add a vertical block
    void add_bl_v(int i, int j, int size);
    // print the contents of the CBoard
    void print();
    
};

#endif /* defined(__unblockme_solver__c_board__) */
