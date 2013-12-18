//
//  e_board.cpp
//  unblockme_solver
//
//  Created by Alexander G Anderson on 12/16/13.
//  Copyright (c) 2013 Alexander G Anderson. All rights reserved.
//

#include "e_board.h"
void EBoard::intialize_static(int _L_X, int _L_Y) {
    L_X = _L_X;
    L_Y = _L_Y;
}

/*
 Builds expanded board from a compressed board
 
 Prints an error if blocks overlap
 */
EBoard::EBoard(CBoard cb) {
    board.resize(L_Y);
    for (int i = 0; i < L_Y; ++i)
        board[i].resize(L_X);
    
    for (int i = 0; i < L_X; ++i) {
        for (int j = 0; j < L_Y; ++j) {
            board[i][j] = EMPTY;
        }
    }

    int b_num = 0;
    for (int i = 0; i < cb.bl_h.size(); ++i) {
        for (int j = 0; j < cb.s_h[i];j++) {
            loc l = cb.bl_h[i];
            if(board[l.first + j][l.second] == EMPTY)
                board[l.first + j][l.second] = b_num;
            else
                printf("ERROR: blocks overlap");
        }
        ++b_num;
    }

    for (int i = 0; i < cb.s_v.size(); ++i) {
        for (int j = 0; j < cb.s_v[i];j++) {
            loc l = cb.bl_v[i];
            if(board[l.first][l.second + j] == EMPTY)
                board[l.first][l.second + j] = b_num;
            else
                printf("ERROR: blocks overlap");
        }
        ++b_num;
    }
    
    
}

// Prints board - cells don't align when more than 100 blocks
void EBoard::print() {
    for (int j = 0; j < L_Y; ++j) {
        for (int i = 0; i < L_X; ++i) {
                
            int v = board[i][j];
            if (v < 10 and v!= EMPTY)
                cout << "  " << v;
            else
                cout << " " << v;
        }
        cout << endl;
    }
    cout << endl;
}

int EBoard::EMPTY = -1;
int EBoard::L_X;
int EBoard::L_Y;
