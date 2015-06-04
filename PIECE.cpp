//
//  PIECE.cpp
//  ChessProject++
//
//  Created by Erich Wellinger on 7/23/13.
//  Copyright (c) 2013 Erich Wellinger. All rights reserved.
//

#include "main.h"

//PIECE Constructor
PIECE::PIECE(const string & _name)
: name(_name) {}

string PIECE::getLocation() {
    return location.location;
};

string PIECE::getName() {
    return name;
};

int PIECE::getColNum() {
    return location.colNum;
}

char PIECE::getCol() {
    return location.col;
};

int PIECE::getRow() {
    return location.row;
};

int PIECE::getMoveNum() {
    return move;
};

void PIECE::setLocation(Square & _location) {
    location = _location;
};

void PIECE::setMoved() {
    move++;
};

void PIECE::setBackMove() {
    move--;
};
