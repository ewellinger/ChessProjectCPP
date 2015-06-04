//
//  KING.cpp
//  ChessProject++
//
//  Created by Erich Wellinger on 7/22/13.
//  Copyright (c) 2013 Erich Wellinger. All rights reserved.
//

#include "main.h"    


bool KING::canMove(Square & _moveLocation, Square (&board)[8][8]) {
    bool canMove = false;
    /*
     This is where you will need to put the rules for KNIGHT movement.
     You will pass this method the Square object that you intend to
     move the piece to and the method should return a boolean value
     whether this move is legal or not.
     */
    if((this->getColNum()-1) <= _moveLocation.colNum <= (this->getColNum()+1)) {
        if((this->getRow()-1) <= _moveLocation.row <= (this->getRow()+1)) {
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








