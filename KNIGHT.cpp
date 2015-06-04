//
//  KNIGHT.cpp
//  ChessProject++
//
//  Created by Erich Wellinger on 7/22/13.
//  Copyright (c) 2013 Erich Wellinger. All rights reserved.
//

#include "main.h"

bool KNIGHT::canMove(Square & _moveLocation, Square (&board)[8][8]) {
    bool canMove = false;
    /*
     This is where you will need to put the rules for KNIGHT movement.
     You will pass this method the Square object that you intend to
     move the piece to and the method should return a boolean value
     whether this move is legal or not.
     */
    
    if(board[this->getColNum()][this->getRow()-1].whiteTile == _moveLocation.whiteTile) {
        return canMove;
    } else if(this->getColNum() == _moveLocation.colNum) {
        return canMove;
    } else if(this->getRow() == _moveLocation.row) {
        return canMove;
    }
    
    /*
     Cycle through to see if the move location has column number +2, +1, -1,
     or -2 from the knight moving.  Then based on the column number it'll see
     if the move location has the right row number
     */
    if(_moveLocation.colNum == (this->getColNum()+2)) {
        if(_moveLocation.row == (this->getRow()+1)) {
            canMove = true;
        } else if(_moveLocation.row == (this->getRow()-1)) {
            canMove = true;
        }
    } else if(_moveLocation.colNum == (this->getColNum()+1)) {
        if(_moveLocation.row == (this->getRow()+2)) {
            canMove = true;
        } else if(_moveLocation.row == (this->getRow()-2)) {
            canMove = true;
        }
    } else if(_moveLocation.colNum == (this->getColNum()-1)) {
        if(_moveLocation.row == (this->getRow()+2)) {
            canMove = true;
        } else if(_moveLocation.row == (this->getRow()-2)) {
            canMove = true;
        }
    } else if(_moveLocation.colNum == (this->getColNum()-2)) {
        if(_moveLocation.row == (this->getRow()+1)) {
            canMove = true;
        } else if(_moveLocation.row == (this->getRow()-1)) {
            canMove = true;
        }
    }
    
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
    
    
    
    return canMove;
};