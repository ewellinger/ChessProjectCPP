//
//  main.h
//  Chess Project
//
//  Created by Erich Wellinger on 6/21/13.
//  Copyright (c) 2013 Erich Wellinger. All rights reserved.
//

#ifndef __Chess_Project__main__
#define __Chess_Project__main__


#include <iostream>
using namespace std;
#include <sstream>
#include <string>

/*
 The colNum and rowNum are the numbers of the respective indices while
 col and row are the letter and number of the board square.
 i.e. board[0][0] is square A1, col is 'A', row is 1, colNum is 0, and 
        rowNum is 0
 */
struct Square {
    bool whiteTile;
    bool occupied;
    string occupiedBy;
    char col;
    int colNum;
    int row;
    int rowNum;
    string location;
};


/*
 The PIECE class will have all of the common elements of the individual
 chess pieces.  The specific pieces will inherit the general code from
 this class.
 */
class PIECE {
    string name;
    Square location;
    int move = 0;
    PIECE(){};  // private constructor will prevent the construction of the base class
protected:
    PIECE(const string & _name);
public:
    string getLocation();
    string getName();
    char getCol();
    int getColNum();
    int getRow();
    int getMoveNum();
    void setLocation(Square & _location);
    void setMoved();
    void setBackMove();
    
};



class PAWN : public PIECE { 
public:
    PAWN(const string & _name) : PIECE(_name) {};
    //~PAWN();  //Destructor
    bool canMove(Square & _moveLocation, Square (&board)[8][8]);
    bool canTake(Square & _moveLocation, Square (&board)[8][8]);
};


class ROOK :public PIECE {
public:
    ROOK(const string & _name) : PIECE(_name) {};
    //~ROOK();  //Destructor
    bool canMove(Square & _moveLocation, Square (&board)[8][8]);
};


class KNIGHT : public PIECE {
public:
    KNIGHT(const string & _name) : PIECE(_name) {};
    //~KNIGHT();  //Destructor
    bool canMove(Square & _moveLocation, Square (&board)[8][8]);
};


class BISHOP : public PIECE {
public:
    BISHOP(const string & _name) : PIECE(_name) {};
    //~BISHOP();  //Destructor
    bool canMove(Square & _moveLocation, Square (&board)[8][8]);
};


class QUEEN : public PIECE {
public:
    QUEEN(const string & _name) : PIECE(_name) {};
    bool canMove(Square & _moveLocation, Square (&board)[8][8]);
};


class KING : public PIECE {
public:
    KING(const string & _name) : PIECE(_name) {};
    bool canMove(Square & _moveLocation, Square (&board)[8][8]);
};






#endif /* defined(__Chess_Project__main__) */
