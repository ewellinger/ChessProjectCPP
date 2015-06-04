//
//  ROOK.cpp
//  ChessProject++
//
//  Created by Erich Wellinger on 7/22/13.
//  Copyright (c) 2013 Erich Wellinger. All rights reserved.
//

#include "main.h"


bool ROOK::canMove(Square & _moveLocation, Square (&board)[8][8]) {
    bool canMove = false;
    
    /*
     This is where you will need to put the rules for ROOK movement.
     You will pass this method the Square object that you intend to
     move the piece to and the method should return a boolean value
     whether this move is legal or not.
     
     */
    
    if(_moveLocation.colNum == this->getColNum()) {
        canMove = true;
        int spacesMoved = _moveLocation.row - this->getRow();
        
        for( int i = 1; i < abs(spacesMoved); i++) {
            if(spacesMoved > 0) {
                if(board[this->getColNum()][this->getRow()-1+i].occupied == true) {
                    cerr << "ERROR: There's A Piece In The Way!" << endl;
                    return false;
                }
            } else {
                if(board[this->getColNum()][this->getRow()-1-i].occupied == true) {
                    cerr << "ERROR: There's A Piece In The Way!" << endl;
                    return false;
                }
            }
        }
    } else if(_moveLocation.row == this->getRow()) {
        canMove = true;
        int spacesMoved = _moveLocation.colNum - this->getColNum();
        
        for( int i = 1; i < abs(spacesMoved); i++) {
            if(spacesMoved > 0) {
                if(board[this->getColNum()+i][this->getRow()-1].occupied == true) {
                    cerr << "ERROR: There's A Piece In The Way!" << endl;
                    return false;
                }
            } else {
                if(board[this->getColNum()-i][this->getRow()-1].occupied == true) {
                    cerr << "ERROR: There's A Piece In The Way!" << endl;
                    return false;
                }
            }
        }
        
    }
    
    
    if(_moveLocation.occupied == true) {
        switch(this->getName().at(0)) {
            case 'w':
                if(_moveLocation.occupiedBy.at(0) == 'w') {
                    cerr << "ERROR: This space is occupied by your own piece!" << endl;
                    canMove = false;
                }
                break;
            case 'b':
                if(_moveLocation.occupiedBy.at(0) == 'b') {
                    cerr << "ERROR: This space is occupied by your own piece!" << endl;
                    canMove = false;
                }
                break;
        }
    }
            
    
    return canMove;
};

