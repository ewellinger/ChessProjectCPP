//
//  PAWN.cpp
//  ChessProject++
//
//  Created by Erich Wellinger on 7/22/13.
//  Completed on 7/26
//  Copyright (c) 2013 Erich Wellinger. All rights reserved.
//

#include "main.h"

/* 
    Not sure about these canMove and canTake methods with the pawn because the pawn
    can move some places but can't take them
 */

bool PAWN::canMove(Square & _moveLocation, Square (&board)[8][8]) {
    bool canMove = true;
    
    /*  
    This is where you will need to put the rules for Pawn movement.
    You will pass this method the Square object that you intend to
    move the piece to and the method should return a boolean value
    whether this move is legal or not.
     */
    
    if(this->getName().at(0) == 'w') {
        int spacesMoved = (_moveLocation.row - this->getRow());
        
        
        //Pawns can't change their column unless they are taking another piece
        if(_moveLocation.col != this->getCol()) {
            canMove = false;
        }
        
        //Pawns can only move one space forward
        if(_moveLocation.row != ( this->getRow() + 1 )) {
            canMove = false;
        }
        
        //Except when it's the first time they have moved, in which case they can move two forward
        if((this->getMoveNum() == 0) && (_moveLocation.row == (this->getRow() + 2))) {
            canMove = true;
        }
        
        /*
         Now we need to evaluate if there are any other pieces which block the movement to
         the indicated location.
         */
        if(canMove == true) {
            if(_moveLocation.occupied == true) {
                canMove = false;
                cerr << "This Move Cannot Be Made Because The Space Is Occupied" << endl;
            }
            
            //Now we'll create a loop to check to see if the squares that were skipped are occupied
            if(canMove == true) {
                for( int i = 1; i < spacesMoved; i++ ) {
                    if(board[_moveLocation.colNum][_moveLocation.rowNum - i].occupied == true) {
                        canMove = false;
                    }
                }
            }
        }
    } else {
        int spacesMoved = abs(_moveLocation.row - this->getRow());
        
        //Pawns can't change their column unless they are taking another piece
        if(_moveLocation.col != this->getCol()) {
            canMove = false;
        }
        
        //Pawns can only move one space forward
        if(_moveLocation.row != ( this->getRow() - 1 )) {
            canMove = false;
        }
        
        //Except when it's the first time they have moved, in which case they can move two forward
        if((this->getMoveNum() == 0) && (_moveLocation.row == (this->getRow() - 2))) {
            canMove = true;
        }
        
        /*
         Now we need to evaluate if there are any other pieces which block the movement to
         the indicated location.
         */
        if(canMove == true) {
            if(_moveLocation.occupied == true) {
                canMove = false;
                cerr << "This move cannot be made because the space is occupied" << endl;
            }
            
            //Now we'll create a loop to check to see if the squares that were skipped are occupied
            if(canMove == true) {
                for( int i = 1; i < spacesMoved; i++ ) {
                    if(board[_moveLocation.colNum][_moveLocation.rowNum + i].occupied == true) {
                        canMove = false;
                    }
                }
            }
        }
    }
    
    if( (canMove == false) && (_moveLocation.occupied == true)) {
        canMove = this->canTake(_moveLocation, board);
    }
    
    return canMove;
};


bool PAWN::canTake(Square & _moveLocation, Square (&board)[8][8]) {
    bool canTake = false;
    /*
     This should be a fairly staight forward method... It should take in the pawn's
     current location and test to make sure the _moveLocation is one of the two places
     a pawn can move to.
     Then the method needs to test whether the square is occupied and if so then it needs 
     to check whether the piece occupying the square is the opposite color from the pawn
     moving
     */
    /*
     I'm not sure if this is actually checking to see if that square is occupied like it
     should be...  Okay, it's now checking to see that the spot is occupied but not to see if it's
     occupied by the opposite color piece...
    */
    
    if(this->getName().at(0) == 'w') {
        if(this->getColNum() == 0) {
            if( (_moveLocation.colNum == 1) && (_moveLocation.row == (this->getRow() + 1))) {
                //if(_moveLocation.occupiedBy) {
                    canTake = true;
                //}
            }
        } else if(this->getColNum() == 7) {
            if( (_moveLocation.colNum == 6) && (_moveLocation.row == (this->getRow() + 1))) {
                canTake = true;
            }
        } else {
            if( _moveLocation.colNum == (this->getColNum() + 1)) {
                if(_moveLocation.row == (this->getRow() + 1)) {
                    canTake = true;
                }
            } else if(_moveLocation.colNum == (this->getColNum() - 1)) {
                if(_moveLocation.row == (this->getRow() + 1)) {
                    canTake = true;
                }
            }
        }
        
        
    } else {
        if(this->getColNum() == 0) {
            if( (_moveLocation.colNum == 1) && (_moveLocation.row == (this->getRow() - 1))) {
                canTake = true;
            }
        } else if(this->getColNum() == 7) {
            if( (_moveLocation.colNum == 6) && (_moveLocation.row == (this->getRow() - 1))) {
                canTake = true;
            }
        } else {
            if( _moveLocation.colNum == (this->getColNum() + 1)) {
                if(_moveLocation.row == (this->getRow() - 1)) {
                    canTake = true;
                }
            }
            if( _moveLocation.colNum == (this->getColNum() - 1)) {
                if(_moveLocation.row == (this->getRow() - 1)) {
                    canTake = true;
                }
            }
        }
    }
    
    return canTake;
}
