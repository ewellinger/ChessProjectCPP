//
//  main.cpp
//  Chess Project
//
//  Created by Erich Wellinger on 6/21/13.
//  Copyright (c) 2013 Erich Wellinger. All rights reserved.
//

#include "main.h"
void createBoard();
void newGame();
void whiteMove();
void blackMove();
void move(PIECE & _pieceBeingMoved, Square & _originalLocation, Square & _newLocation);
void takeBackMove(PIECE &_movedPiece, Square & _originalLocation, PIECE & _takenPiece, Square & _takenLocation);
void takePiece(Square & _moveLocation);
bool whiteCheck();
bool blackCheck();
bool checkMate();


//Create the board
Square board[8][8];  //board[col][row] ... i.e. board[1][0] is B1, board[2][0] is C1...
Square graveYard;
int moveNum;
bool gameOver = false;

//Creating the pieces
PAWN wp1( "wp1" );
PAWN wp2( "wp2" );
PAWN wp3( "wp3" );
PAWN wp4( "wp4" );
PAWN wp5( "wp5" );
PAWN wp6( "wp6" );
PAWN wp7( "wp7" );
PAWN wp8( "wp8" );
ROOK wr1( "wr1" );
ROOK wr2( "wr2" );
KNIGHT wk1( "wk1" );
KNIGHT wk2( "wk2" );
BISHOP wb1( "wb1" );
BISHOP wb2( "wb2" );
QUEEN wQUEEN( "wQUEEN" );
KING wKING( "wKING" );
PAWN bp1( "bp1" );
PAWN bp2( "bp2" );
PAWN bp3( "bp3" );
PAWN bp4( "bp4" );
PAWN bp5( "bp5" );
PAWN bp6( "bp6" );
PAWN bp7( "bp7" );
PAWN bp8( "bp8" );
ROOK br1( "br1" );
ROOK br2( "br2" );
KNIGHT bk1( "bk1" );
KNIGHT bk2( "bk2" );
BISHOP bb1( "bb1" );
BISHOP bb2( "bb2" );
QUEEN bQUEEN( "bQUEEN" );
KING bKING( "bKING" );




int main( int argc, char ** argv ) {
    
    
    //createBoard() method will initialize the board[][] members with the proper data
    createBoard();
    
    
    //newGame() method is called to place the pieces in the proper places
    newGame();
    
    
    while(gameOver == false) {
        if(moveNum % 2 == 0) {
            cout << "\nMove Number: " << ((moveNum / 2) + 1) << endl;
            whiteMove();
            if(checkMate() == true) {
                cout << "WHITE HAS WON!" << endl;
                gameOver = true;
            }else if(blackCheck() == true) {
                cout << "Black's King Is In Check!" << endl;
                cout << "Protect Your Leader Or You Lose The War!" << endl;
            } //if
        } else {
            cout << "\nMove Number: " << ((moveNum + 1) / 2) << endl;
            blackMove();
            if(checkMate() == true) {
                cout << "BLACK HAS WON!" << endl;
                gameOver = true;
            }else if(whiteCheck() == true) {
                cout << "White's King Is In Check!" << endl;
                cout << "Protect Your Leader Or You Lose The War!" << endl;
            } //if
        }
    }
    
    return 0;
}

/*
 Create Board Method: Initializes the board with the proper data
 */
void createBoard() {
    //Initialize the board with the color marking
    for( int i = 0; i < 8; i++ ) {
        if( (i % 2) == 0) {
            for( int j = 0; j < 8; (j += 2)) {
                board[i][j].occupied = false;  //Creating the black squares
                board[i][j].whiteTile = false;
            }
            for( int j = 1; j < 8; (j += 2)) {
                board[i][j].occupied = false;
                board[i][j].whiteTile = true;
            }
        }
        else {
            for( int j = 0; j < 8; (j += 2) ) {
                board[i][j].occupied = false;  //Creating the white squares
                board[i][j].whiteTile = true;
            }
            for( int j = 1; j < 8; (j += 2) ) {
                board[i][j].occupied = false;
                board[i][j].whiteTile = false;
            }
        }
    }
    //This assigns the proper column marker, row #, and location tag
    for( int i = 0; i < 8; i++ ) {
        for( int j = 0; j < 8; j++ ) {
            board[i][j].col = 'A' + i;
            board[i][j].colNum = i;
            board[i][j].row = (j + 1);
            board[i][j].rowNum = j;
            stringstream loc;
            loc << board[i][j].col << board[i][j].row;
            board[i][j].location = loc.str();
            board[i][j].occupiedBy = "-";
        }
    }
    
    graveYard.col = '-';
    graveYard.colNum = -1;
    graveYard.row = -1;
    graveYard.rowNum = -1;
    graveYard.location = "R.I.P.";

}

/*
 New Game Method: This will initialize the pieces into the proper places
 */
void newGame() {
    
    cout << "newGame method here!\n" << endl;
    
    moveNum = 0;
    gameOver = false;
    
    
    //Set the Location of the White Team
    wp1.setLocation(board[0][1]);
    board[0][1].occupied = true;
    board[0][1].occupiedBy = wp1.getName();
    wp2.setLocation(board[1][1]);
    board[1][1].occupied = true;
    board[1][1].occupiedBy = wp2.getName();
    wp3.setLocation(board[2][1]);
    board[2][1].occupied = true;
    board[2][1].occupiedBy = wp3.getName();
    wp4.setLocation(board[3][1]);
    board[3][1].occupied = true;
    board[3][1].occupiedBy = wp4.getName();
    wp5.setLocation(board[4][1]);
    board[4][1].occupied = true;
    board[4][1].occupiedBy = wp5.getName();
    wp6.setLocation(board[5][1]);
    board[5][1].occupied = true;
    board[5][1].occupiedBy = wp6.getName();
    wp7.setLocation(board[6][1]);
    board[6][1].occupied = true;
    board[6][1].occupiedBy = wp7.getName();
    wp8.setLocation(board[7][1]);
    board[7][1].occupied = true;
    board[7][1].occupiedBy = wp8.getName();
    wr1.setLocation(board[0][0]);
    board[0][0].occupied = true;
    board[0][0].occupiedBy = wr1.getName();
    wr2.setLocation(board[7][0]);
    board[7][0].occupied = true;
    board[7][0].occupiedBy = wr2.getName();
    wk1.setLocation(board[1][0]);
    board[1][0].occupied = true;
    board[1][0].occupiedBy = wk1.getName();
    wk2.setLocation(board[6][0]);
    board[6][0].occupied = true;
    board[6][0].occupiedBy = wk2.getName();
    wb1.setLocation(board[2][0]);
    board[2][0].occupied = true;
    board[2][0].occupiedBy = wb1.getName();
    wb2.setLocation(board[5][0]);
    board[5][0].occupied = true;
    board[5][0].occupiedBy = wb2.getName();
    wQUEEN.setLocation(board[3][0]);
    board[3][0].occupied = true;
    board[3][0].occupiedBy = wQUEEN.getName();
    wKING.setLocation(board[4][0]);
    board[4][0].occupied = true;
    board[4][0].occupiedBy = wKING.getName();
    
    
    //Set the location of the Black Team
    bp1.setLocation(board[0][6]);
    board[0][6].occupied = true;
    board[0][6].occupiedBy = bp1.getName();
    bp2.setLocation(board[1][6]);
    board[1][6].occupied = true;
    board[1][6].occupiedBy = bp2.getName();
    bp3.setLocation(board[2][6]);
    board[2][6].occupied = true;
    board[2][6].occupiedBy = bp3.getName();
    bp4.setLocation(board[3][6]);
    board[3][6].occupied = true;
    board[3][6].occupiedBy = bp4.getName();
    bp5.setLocation(board[4][6]);
    board[4][6].occupied = true;
    board[4][6].occupiedBy = bp5.getName();
    bp6.setLocation(board[5][6]);
    board[5][6].occupied = true;
    board[5][6].occupiedBy = bp6.getName();
    bp7.setLocation(board[6][6]);
    board[6][6].occupied = true;
    board[6][6].occupiedBy = bp7.getName();
    bp8.setLocation(board[7][6]);
    board[7][6].occupied = true;
    board[7][6].occupiedBy = bp8.getName();
    br1.setLocation(board[0][7]);
    board[0][7].occupied = true;
    board[0][7].occupiedBy = br1.getName();
    br2.setLocation(board[7][7]);
    board[7][7].occupied = true;
    board[7][7].occupiedBy = br2.getName();
    bk1.setLocation(board[1][7]);
    board[1][7].occupied = true;
    board[1][7].occupiedBy = bk1.getName();
    bk2.setLocation(board[6][7]);
    board[6][7].occupied = true;
    board[6][7].occupiedBy = bk2.getName();
    bb1.setLocation(board[2][7]);
    board[2][7].occupied = true;
    board[2][7].occupiedBy = bb1.getName();
    bb2.setLocation(board[5][7]);
    board[5][7].occupied = true;
    board[5][7].occupiedBy = bb2.getName();
    bQUEEN.setLocation(board[3][7]);
    board[3][7].occupied = true;
    board[3][7].occupiedBy = bQUEEN.getName();
    bKING.setLocation(board[4][7]);
    board[4][7].occupied = true;
    board[4][7].occupiedBy = bKING.getName();
}




/*
 Move Method: This will determine which team's turn it is and ask them to input
 which piece they want to move and then where they want to move the piece to.
 Then it will increment the moveNum counter and check to see if any of the Kings
 are in check.
 */

void whiteMove() {
    cout << "It's White's Turn!\n" << endl;
    
    bool error = false;  //This is used for input validation
    string input;
    char _col;
    int _colNum;
    int _row;
    // userInput will be used to store the address of the indicated board square
    Square * userInput;
    Square * moveInput;
    
    /* 
     Create pointers for each of the respective pieces and use a typeChoice
     counter to indicate the type of piece chosen and thus which pointer to 
     use.
        typeChoice = 1 indcates a PAWN piece
        typeChoice = 2 indicates a ROOK piece
        typeChoice = 3 indicates a KNIGHT piece
        typeChoice = 4 indicates a BISHOP piece
        typeChoice = 5 indicates a QUEEN piece
        typeChoice = 6 indicates a KING piece
     */
    int typeChoice = 0;
    PAWN * _pawnInput;
    ROOK * _rookInput;
    KNIGHT * _knightInput;
    BISHOP * _bishopInput;
    QUEEN * _queenInput;
    KING * _kingInput;
    PIECE * _userInput;  //--Might need this for the move() method
    PIECE * _takenPiece = nullptr;
    
    //Get the User Input for which piece they want to move
    do {
        error = false;
        cout << "Please choose which Piece to move by entering it's location:  ";
        cin >> input;
        if(input.length() != 2) {
            cerr << "Error: Improper Input!" << endl;
            cerr << "Enter the Column Letter and the Row Number of Which Piece You Want to Move\n" << endl;
            error = true;
        }
        
        _col = input.at(0);
        _row = input.at(1) - 48;
        
        //Verifies a legitimate column letter
        switch(_col) {
            case 'a':
                _col = 'A';
                break;
            case 'b':
                _col = 'B';
                break;
            case 'c':
                _col = 'C';
                break;
            case 'd':
                _col = 'D';
                break;
            case 'e':
                _col = 'E';
                break;
            case 'f':
                _col = 'F';
                break;
            case 'g':
                _col = 'G';
                break;
            case 'h':
                _col = 'H';
                break;
            case 'A':    
            case 'B':    
            case 'C':    
            case 'D':    
            case 'E':    
            case 'F':    
            case 'G':    
            case 'H':
                break;
            default:
                cerr << "ERROR: Inproper Column Input\n" << endl;
                cerr << "Please Enter A Letter A through H\n" << endl;
                error = true;
        }
        
        //Verifies a legitimate row #
        switch(_row) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                break;
            default:
                cerr << "ERROR: Inproper Row Input\n" << endl;
                cerr << "Please Enter a Number 1 through 8" << endl;
                error = true;
        }
    } while(error == true);
    
    cout << "You entered Column " << _col << " and row " << _row << endl;
    
    _row -= 1;
    _colNum = _col - 'A';
    
    userInput = &board[_colNum][_row];
    
    //Verifies that the square indicated is occupied by a white piece
    if(userInput->occupied == false) {
        cerr << "ERROR: There Is No Piece At This Location\n" << endl;
        return;
    } else {
        if(userInput->occupiedBy.at(0) != 'w') {
            cerr << "ERROR: There Is No White Piece At This Location\n" << endl;
            return;
        }
    }

    
    /*
     This sets up the _userInput pointer, respective piece type pointer, and 
     the typeChoice counter
     */
    if( userInput->occupiedBy.at(1) == 'p' ) {
        switch(userInput->occupiedBy.at(2)) {
            case '1':
                _pawnInput = &wp1;
                _userInput = &wp1;
                typeChoice = 1;
                break;
            case '2':
                _pawnInput = &wp2;
                _userInput = &wp2;
                typeChoice = 1;
                break;
            case '3':
                _pawnInput = &wp3;
                _userInput = &wp3;
                typeChoice = 1;
                break;
            case '4':
                _pawnInput = &wp4;
                _userInput = &wp4;
                typeChoice = 1;
                break;
            case '5':
                _pawnInput = &wp5;
                _userInput = &wp5;
                typeChoice = 1;
                break;
            case '6':
                _pawnInput = &wp6;
                _userInput = &wp6;
                typeChoice = 1;
                break;
            case '7':
                _pawnInput = &wp7;
                _userInput = &wp7;
                typeChoice = 1;
                break;
            case '8':
                _pawnInput = &wp8;
                _userInput = &wp8;
                typeChoice = 1;
                break;
        }
    } else if( userInput->occupiedBy.at(1) == 'r' ) {
        switch(userInput->occupiedBy.at(2)) {
            case '1':
                _rookInput = &wr1;
                _userInput = &wr1;
                typeChoice = 2;
                break;
            case '2':
                _rookInput = &wr2;
                _userInput = &wr2;
                typeChoice = 2;
                break;
        }
    } else if( userInput->occupiedBy.at(1) == 'k') {
        switch(userInput->occupiedBy.at(2)) {
            case '1':
                _knightInput = &wk1;
                _userInput = &wk1;
                typeChoice = 3;
                break;
            case '2':
                _knightInput = &wk2;
                _userInput = &wk2;
                typeChoice = 3;
                break;
        }
    } else if(userInput->occupiedBy.at(1) == 'b') {
        switch(userInput->occupiedBy.at(2)) {
            case '1':
                _bishopInput = &wb1;
                _userInput = &wb1;
                typeChoice = 4;
                break;
            case '2':
                _bishopInput = &wb2;
                _userInput = &wb2;
                typeChoice = 4;
                break;
        }
    } else if(userInput->occupiedBy.at(1) == 'Q') {
        _queenInput = &wQUEEN;
        _userInput = &wQUEEN;
        typeChoice = 5;
    } else {
        _kingInput = &wKING;
        _userInput = &wKING;
        typeChoice = 6;
    }
    
    
    /*
     Now we need to get the input for where to move the piece to and perform the proper 
     input verification
     */
    do {
        error = false;
        cout << "Enter Where You Would Like to Move Piece " << userInput->occupiedBy << ":  ";
        cin >> input;
        //Verify input is two characters long
        if(input.length() != 2) {
            cerr << "Error: Improper Input!\n" << endl;
            cerr << "Enter the Column Letter and the Row Number of Where You Want to Move\n" << endl;
            error = true;
        }
        _col = input.at(0);
        _row = input.at(1) - 48;
        
        //Verifies a legitimate column letter
        switch(_col) {
            case 'a':
                _col = 'A';
                break;
            case 'b':
                _col = 'B';
                break;
            case 'c':
                _col = 'C';
                break;
            case 'd':
                _col = 'D';
                break;
            case 'e':
                _col = 'E';
                break;
            case 'f':
                _col = 'F';
                break;
            case 'g':
                _col = 'G';
                break;
            case 'h':
                _col = 'H';
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
                break;
            default:
                cerr << "ERROR: Inproper Column Input\n" << endl;
                cerr << "Please Enter A Letter A through H\n" << endl;
                error = true;
        }
        

        //Verifies a legitimate row #
        switch(_row) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                break;
            default:
                cerr << "ERROR: Inproper Row Input\n" << endl;
                cerr << "Please Enter a Number 1 through 8" << endl;
                error = true;
        }
        
    } while(error == true);
    
    cout << "You entered to move " << _userInput->getName() << " to Column " << _col
        << " and row " << _row << endl;
    
    _row -= 1;
    _colNum = _col - 'A';
    
    moveInput = &board[_colNum][_row];
    
    /*
     At this point in the method we have the following pointers set up:
            userInput  -  This is a pointer to the location the piece is originally in
            moveInput  -  This is a pointer to the location the user wants to move the piece to
            _userInput  -  This is a PIECE pointer to the piece the user wants to move
                           NOTE: You CANNOT access the piece's canMove(board[-][-]) method with this pointer
            _pawnInput  -  This is a pointer to the specific pawn if the piece chosen is, in fact, a pawn.
            _rookInput
            etc...
     */
    
    /*
     Now we have one of these piece pointers pointing to the selected piece and
     the typeChoice indicating which pointer should be used.  Now we will implement
     a switch on typeChoice to execute the proper code.
     */
    switch(typeChoice) {
        case 1:
            if(_pawnInput->canMove(*moveInput, board) == false) {
                cerr << "ERROR: This is an Invalid Move for a Pawn!\n" << endl;
                return;
            }
            
            if(moveInput->occupied == true) {
                if( moveInput->occupiedBy.at(1) == 'p' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bp1;
                            break;
                        case '2':
                            _takenPiece = &bp2;
                            break;
                        case '3':
                            _takenPiece = &bp3;
                            break;
                        case '4':
                            _takenPiece = &bp4;
                            break;
                        case '5':
                            _takenPiece = &bp5;
                            break;
                        case '6':
                            _takenPiece = &bp6;
                            break;
                        case '7':
                            _takenPiece = &bp7;
                            break;
                        case '8':
                            _takenPiece = &bp8;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'r' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &br1;
                            break;
                        case '2':
                            _takenPiece = &br2;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'k') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bk1;
                            break;
                        case '2':
                            _takenPiece = &bk2;
                            break;
                    }
                } else if(moveInput->occupiedBy.at(1) == 'b') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bb1;
                            break;
                        case '2':
                            _takenPiece = &bb2;
                            break;
                    }
                } else {
                    _takenPiece = &bQUEEN;
                }
            }
            
            
            //This actually moves the piece to the new location and updates the statuses of the relevant squares
            //Might also want this to delete any piece that has been taken in the move...
            move(*_userInput, *userInput, *moveInput);
            break;
        case 2:
            if(_rookInput->canMove(*moveInput, board) == false) {
                cerr << "ERROR: This Is An Invalid Move For A Rook!\n" << endl;
                return;
            }
            
            if(moveInput->occupied == true) {
                if( moveInput->occupiedBy.at(1) == 'p' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bp1;
                            break;
                        case '2':
                            _takenPiece = &bp2;
                            break;
                        case '3':
                            _takenPiece = &bp3;
                            break;
                        case '4':
                            _takenPiece = &bp4;
                            break;
                        case '5':
                            _takenPiece = &bp5;
                            break;
                        case '6':
                            _takenPiece = &bp6;
                            break;
                        case '7':
                            _takenPiece = &bp7;
                            break;
                        case '8':
                            _takenPiece = &bp8;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'r' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &br1;
                            break;
                        case '2':
                            _takenPiece = &br2;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'k') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bk1;
                            break;
                        case '2':
                            _takenPiece = &bk2;
                            break;
                    }
                } else if(moveInput->occupiedBy.at(1) == 'b') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bb1;
                            break;
                        case '2':
                            _takenPiece = &bb2;
                            break;
                    }
                } else {
                    _takenPiece = &bQUEEN;
                }
            }
            
            
            //This actually moves the piece to the new location and updates the statuses of the relevant squares
            //Might also want this to delete any piece that has been taken in the move...
            move(*_userInput, *userInput, *moveInput);
            break;
        case 3:
            if(_knightInput->canMove(*moveInput, board) == false) {
                cerr << "ERROR: This is an Invalid Move for a Knight!\n" << endl;
                return;
            }
            
            if(moveInput->occupied == true) {
                if( moveInput->occupiedBy.at(1) == 'p' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bp1;
                            break;
                        case '2':
                            _takenPiece = &bp2;
                            break;
                        case '3':
                            _takenPiece = &bp3;
                            break;
                        case '4':
                            _takenPiece = &bp4;
                            break;
                        case '5':
                            _takenPiece = &bp5;
                            break;
                        case '6':
                            _takenPiece = &bp6;
                            break;
                        case '7':
                            _takenPiece = &bp7;
                            break;
                        case '8':
                            _takenPiece = &bp8;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'r' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &br1;
                            break;
                        case '2':
                            _takenPiece = &br2;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'k') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bk1;
                            break;
                        case '2':
                            _takenPiece = &bk2;
                            break;
                    }
                } else if(moveInput->occupiedBy.at(1) == 'b') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bb1;
                            break;
                        case '2':
                            _takenPiece = &bb2;
                            break;
                    }
                } else {
                    _takenPiece = &bQUEEN;
                }
            }
            
            
            //This actually moves the piece to the new location and updates the statuses of the relevant squares
            //Might also want this to delete any piece that has been taken in the move...
            move(*_userInput, *userInput, *moveInput);
            break;
        case 4:
            if(_bishopInput->canMove(*moveInput, board) == false) {
                cerr << "ERROR: This is an Invalid Move for a Bishop!\n" << endl;
                return;
            }
            
            if(moveInput->occupied == true) {
                if( moveInput->occupiedBy.at(1) == 'p' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bp1;
                            break;
                        case '2':
                            _takenPiece = &bp2;
                            break;
                        case '3':
                            _takenPiece = &bp3;
                            break;
                        case '4':
                            _takenPiece = &bp4;
                            break;
                        case '5':
                            _takenPiece = &bp5;
                            break;
                        case '6':
                            _takenPiece = &bp6;
                            break;
                        case '7':
                            _takenPiece = &bp7;
                            break;
                        case '8':
                            _takenPiece = &bp8;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'r' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &br1;
                            break;
                        case '2':
                            _takenPiece = &br2;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'k') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bk1;
                            break;
                        case '2':
                            _takenPiece = &bk2;
                            break;
                    }
                } else if(moveInput->occupiedBy.at(1) == 'b') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bb1;
                            break;
                        case '2':
                            _takenPiece = &bb2;
                            break;
                    }
                } else {
                    _takenPiece = &bQUEEN;
                }
            }
            
            
            //This actually moves the piece to the new location and updates the statuses of the relevant squares
            //Might also want this to delete any piece that has been taken in the move...
            move(*_userInput, *userInput, *moveInput);
            break;
        case 5:
            if(_queenInput->canMove(*moveInput, board) == false) {
                cerr << "ERROR: This is an Invalid Move for a Queen!\n" << endl;
                return;
            }
            
            if(moveInput->occupied == true) {
                if( moveInput->occupiedBy.at(1) == 'p' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bp1;
                            break;
                        case '2':
                            _takenPiece = &bp2;
                            break;
                        case '3':
                            _takenPiece = &bp3;
                            break;
                        case '4':
                            _takenPiece = &bp4;
                            break;
                        case '5':
                            _takenPiece = &bp5;
                            break;
                        case '6':
                            _takenPiece = &bp6;
                            break;
                        case '7':
                            _takenPiece = &bp7;
                            break;
                        case '8':
                            _takenPiece = &bp8;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'r' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &br1;
                            break;
                        case '2':
                            _takenPiece = &br2;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'k') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bk1;
                            break;
                        case '2':
                            _takenPiece = &bk2;
                            break;
                    }
                } else if(moveInput->occupiedBy.at(1) == 'b') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bb1;
                            break;
                        case '2':
                            _takenPiece = &bb2;
                            break;
                    }
                } else {
                    _takenPiece = &bQUEEN;
                }
            }
            
            
            //This actually moves the piece to the new location and updates the statuses of the relevant squares
            //Might also want this to delete any piece that has been taken in the move...
            move(*_userInput, *userInput, *moveInput);
            break;
        case 6:
            if(_kingInput->canMove(*moveInput, board) == false) {
                cerr << "ERROR: This is an Invalid Move for a King!\n" << endl;
                return;
            }
            
            if(moveInput->occupied == true) {
                if( moveInput->occupiedBy.at(1) == 'p' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bp1;
                            break;
                        case '2':
                            _takenPiece = &bp2;
                            break;
                        case '3':
                            _takenPiece = &bp3;
                            break;
                        case '4':
                            _takenPiece = &bp4;
                            break;
                        case '5':
                            _takenPiece = &bp5;
                            break;
                        case '6':
                            _takenPiece = &bp6;
                            break;
                        case '7':
                            _takenPiece = &bp7;
                            break;
                        case '8':
                            _takenPiece = &bp8;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'r' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &br1;
                            break;
                        case '2':
                            _takenPiece = &br2;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'k') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bk1;
                            break;
                        case '2':
                            _takenPiece = &bk2;
                            break;
                    }
                } else if(moveInput->occupiedBy.at(1) == 'b') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &bb1;
                            break;
                        case '2':
                            _takenPiece = &bb2;
                            break;
                    }
                } else {
                    _takenPiece = &bQUEEN;
                }
            }
            
            
            //This actually moves the piece to the new location and updates the statuses of the relevant squares
            //Might also want this to delete any piece that has been taken in the move...
            move(*_userInput, *userInput, *moveInput);
            break;
    }
    
    
    if(whiteCheck() == true) {
        cerr << "ERROR: You Are In Check!" << endl;
        cerr << "Please Try A Different Move" << endl;
        takeBackMove( *_userInput, *userInput, *_takenPiece, *moveInput);
        return;
    }
    
    
    moveNum++;
    
}

void blackMove() {
    cout << "It's Black's Turn!\n" << endl;
    
    bool error = false;  //This is used for input validation
    string input;
    char _col;
    int _colNum;
    int _row;
    // userInput will be used to store the address of the indicated board square
    Square * userInput;
    Square * moveInput;
    
    /*
     Create pointers for each of the respective pieces and use a typeChoice
     counter to indicate the type of piece chosen and thus which pointer to
     use.
     typeChoice = 1 indcates a PAWN piece
     typeChoice = 2 indicates a ROOK piece
     typeChoice = 3 indicates a KNIGHT piece
     typeChoice = 4 indicates a BISHOP piece
     typeChoice = 5 indicates a QUEEN piece
     typeChoice = 6 indicates a KING piece
     */
    int typeChoice = 0;
    PAWN * _pawnInput;
    ROOK * _rookInput;
    KNIGHT * _knightInput;
    BISHOP * _bishopInput;
    QUEEN * _queenInput;
    KING * _kingInput;
    PIECE * _userInput;  //--Might need this for the move() method
    PIECE * _takenPiece = nullptr;
    
    //Get the User Input for which piece they want to move
    do {
        error = false;
        cout << "Please choose which Piece to move by entering it's location:  ";
        cin >> input;
        if(input.length() != 2) {
            cerr << "Error: Improper Input!" << endl;
            cerr << "Enter the Column Letter and the Row Number of Which Piece You Want to Move\n" << endl;
            error = true;
        }
        
        _col = input.at(0);
        _row = input.at(1) - 48;
        
        //Verifies a legitimate column letter
        switch(_col) {
            case 'a':
                _col = 'A';
                break;
            case 'b':
                _col = 'B';
                break;
            case 'c':
                _col = 'C';
                break;
            case 'd':
                _col = 'D';
                break;
            case 'e':
                _col = 'E';
                break;
            case 'f':
                _col = 'F';
                break;
            case 'g':
                _col = 'G';
                break;
            case 'h':
                _col = 'H';
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
                break;
            default:
                cerr << "ERROR: Inproper Column Input\n" << endl;
                cerr << "Please Enter A Letter A through H\n" << endl;
                error = true;
        }
        
        //Verifies a legitimate row #
        switch(_row) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                break;
            default:
                cerr << "ERROR: Inproper Row Input\n" << endl;
                cerr << "Please Enter a Number 1 through 8" << endl;
                error = true;
        }
    } while(error == true);
    
    cout << "You entered Column " << _col << " and row " << _row << endl;
    
    _row -= 1;
    _colNum = _col - 'A';
    
    userInput = &board[_colNum][_row];
    
    //Verifies that the square indicated is occupied by a black piece
    if(userInput->occupied == false) {
        cerr << "ERROR: There Is No Piece At This Location\n" << endl;
        return;
    } else {
        if(userInput->occupiedBy.at(0) != 'b') {
            cerr << "ERROR: There Is No Black Piece At This Location\n" << endl;
            return;
        }
    }
    
    
    /*
     This sets up the _userInput pointer, respective piece type pointer, and
     the typeChoice counter
     */
    if( userInput->occupiedBy.at(1) == 'p' ) {
        switch(userInput->occupiedBy.at(2)) {
            case '1':
                _pawnInput = &bp1;
                _userInput = &bp1;
                typeChoice = 1;
                break;
            case '2':
                _pawnInput = &bp2;
                _userInput = &bp2;
                typeChoice = 1;
                break;
            case '3':
                _pawnInput = &bp3;
                _userInput = &bp3;
                typeChoice = 1;
                break;
            case '4':
                _pawnInput = &bp4;
                _userInput = &bp4;
                typeChoice = 1;
                break;
            case '5':
                _pawnInput = &bp5;
                _userInput = &bp5;
                typeChoice = 1;
                break;
            case '6':
                _pawnInput = &bp6;
                _userInput = &bp6;
                typeChoice = 1;
                break;
            case '7':
                _pawnInput = &bp7;
                _userInput = &bp7;
                typeChoice = 1;
                break;
            case '8':
                _pawnInput = &bp8;
                _userInput = &bp8;
                typeChoice = 1;
                break;
        }
    } else if( userInput->occupiedBy.at(1) == 'r' ) {
        switch(userInput->occupiedBy.at(2)) {
            case '1':
                _rookInput = &br1;
                _userInput = &br1;
                typeChoice = 2;
                break;
            case '2':
                _rookInput = &br2;
                _userInput = &br2;
                typeChoice = 2;
                break;
        }
    } else if( userInput->occupiedBy.at(1) == 'k') {
        switch(userInput->occupiedBy.at(2)) {
            case '1':
                _knightInput = &bk1;
                _userInput = &bk1;
                typeChoice = 3;
                break;
            case '2':
                _knightInput = &bk2;
                _userInput = &bk2;
                typeChoice = 3;
                break;
        }
    } else if(userInput->occupiedBy.at(1) == 'b') {
        switch(userInput->occupiedBy.at(2)) {
            case '1':
                _bishopInput = &bb1;
                _userInput = &bb1;
                typeChoice = 4;
                break;
            case '2':
                _bishopInput = &bb2;
                _userInput = &bb2;
                typeChoice = 4;
                break;
        }
    } else if(userInput->occupiedBy.at(1) == 'Q') {
        _queenInput = &bQUEEN;
        _userInput = &bQUEEN;
        typeChoice = 5;
    } else {
        _kingInput = &bKING;
        _userInput = &bKING;
        typeChoice = 6;
    }
    
    
    /*
     Now we need to get the input for where to move the piece to and perform the proper
     input verification
     */
    do {
        error = false;
        cout << "Enter Where You Would Like to Move Piece " << userInput->occupiedBy << ":  ";
        cin >> input;
        //Verify input is two characters long
        if(input.length() != 2) {
            cerr << "Error: Improper Input!\n" << endl;
            cerr << "Enter the Column Letter and the Row Number of Where You Want to Move\n" << endl;
            error = true;
        }
        _col = input.at(0);
        _row = input.at(1) - 48;
        
        //Verifies a legitimate column letter
        switch(_col) {
            case 'a':
                _col = 'A';
                break;
            case 'b':
                _col = 'B';
                break;
            case 'c':
                _col = 'C';
                break;
            case 'd':
                _col = 'D';
                break;
            case 'e':
                _col = 'E';
                break;
            case 'f':
                _col = 'F';
                break;
            case 'g':
                _col = 'G';
                break;
            case 'h':
                _col = 'H';
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
                break;
            default:
                cerr << "ERROR: Inproper Column Input\n" << endl;
                cerr << "Please Enter A Letter A through H\n" << endl;
                error = true;
        }
        
        
        //Verifies a legitimate row #
        switch(_row) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                break;
            default:
                cerr << "ERROR: Inproper Row Input\n" << endl;
                cerr << "Please Enter a Number 1 through 8" << endl;
                error = true;
        }
        
    } while(error == true);
    
    cout << "You entered to move " << _userInput->getName() << " to Column " << _col
    << " and row " << _row << endl;
    
    _row -= 1;
    _colNum = _col - 'A';
    
    moveInput = &board[_colNum][_row];
    
    /*
     At this point in the method we have the following pointers set up:
     userInput  -  This is a pointer to the location the piece is originally in
     moveInput  -  This is a pointer to the location the user wants to move the piece to
     _userInput  -  This is a PIECE pointer to the piece the user wants to move
     NOTE: You CANNOT access the piece's canMove(board[-][-]) method with this pointer
     _pawnInput  -  This is a pointer to the specific pawn if the piece chosen is, in fact, a pawn.
     _rookInput
     etc...
     */
    
    /*
     Now we have one of these piece pointers pointing to the selected piece and
     the typeChoice indicating which pointer should be used.  Now we will implement
     a switch on typeChoice to execute the proper code.
     */
    switch(typeChoice) {
        case 1:
            if(_pawnInput->canMove(*moveInput, board) == false) {
                cerr << "ERROR: This is an Invalid Move for a Pawn!\n" << endl;
                return;
            }
            
            if(moveInput->occupied == true) {
                if( moveInput->occupiedBy.at(1) == 'p' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wp1;
                            break;
                        case '2':
                            _takenPiece = &wp2;
                            break;
                        case '3':
                            _takenPiece = &wp3;
                            break;
                        case '4':
                            _takenPiece = &wp4;
                            break;
                        case '5':
                            _takenPiece = &wp5;
                            break;
                        case '6':
                            _takenPiece = &wp6;
                            break;
                        case '7':
                            _takenPiece = &wp7;
                            break;
                        case '8':
                            _takenPiece = &wp8;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'r' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wr1;
                            break;
                        case '2':
                            _takenPiece = &wr2;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'k') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wk1;
                            break;
                        case '2':
                            _takenPiece = &wk2;
                            break;
                    }
                } else if(moveInput->occupiedBy.at(1) == 'b') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wb1;
                            break;
                        case '2':
                            _takenPiece = &wb2;
                            break;
                    }
                } else {
                    _takenPiece = &wQUEEN;
                } 
            }
            
                        
            //This actually moves the piece to the new location and updates the statuses of the relevant squares
            //Might also want this to delete any piece that has been taken in the move...
            move(*_userInput, *userInput, *moveInput);
            break;
        case 2:
            if(_rookInput->canMove(*moveInput, board) == false) {
                cerr << "ERROR: This is an Invalid Move for a Rook!\n" << endl;
                return;
            }
            
            if(moveInput->occupied == true) {
                if( moveInput->occupiedBy.at(1) == 'p' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wp1;
                            break;
                        case '2':
                            _takenPiece = &wp2;
                            break;
                        case '3':
                            _takenPiece = &wp3;
                            break;
                        case '4':
                            _takenPiece = &wp4;
                            break;
                        case '5':
                            _takenPiece = &wp5;
                            break;
                        case '6':
                            _takenPiece = &wp6;
                            break;
                        case '7':
                            _takenPiece = &wp7;
                            break;
                        case '8':
                            _takenPiece = &wp8;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'r' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wr1;
                            break;
                        case '2':
                            _takenPiece = &wr2;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'k') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wk1;
                            break;
                        case '2':
                            _takenPiece = &wk2;
                            break;
                    }
                } else if(moveInput->occupiedBy.at(1) == 'b') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wb1;
                            break;
                        case '2':
                            _takenPiece = &wb2;
                            break;
                    }
                } else {
                    _takenPiece = &wQUEEN;
                }
            }

            
            
            //This actually moves the piece to the new location and updates the statuses of the relevant squares
            //Might also want this to delete any piece that has been taken in the move...
            move(*_userInput, *userInput, *moveInput);
            break;
        case 3:
            if(_knightInput->canMove(*moveInput, board) == false) {
                cerr << "ERROR: This is an Invalid Move for a Knight!\n" << endl;
                return;
            }
            
            if(moveInput->occupied == true) {
                if( moveInput->occupiedBy.at(1) == 'p' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wp1;
                            break;
                        case '2':
                            _takenPiece = &wp2;
                            break;
                        case '3':
                            _takenPiece = &wp3;
                            break;
                        case '4':
                            _takenPiece = &wp4;
                            break;
                        case '5':
                            _takenPiece = &wp5;
                            break;
                        case '6':
                            _takenPiece = &wp6;
                            break;
                        case '7':
                            _takenPiece = &wp7;
                            break;
                        case '8':
                            _takenPiece = &wp8;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'r' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wr1;
                            break;
                        case '2':
                            _takenPiece = &wr2;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'k') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wk1;
                            break;
                        case '2':
                            _takenPiece = &wk2;
                            break;
                    }
                } else if(moveInput->occupiedBy.at(1) == 'b') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wb1;
                            break;
                        case '2':
                            _takenPiece = &wb2;
                            break;
                    }
                } else {
                    _takenPiece = &wQUEEN;
                }
            }

            
            //This actually moves the piece to the new location and updates the statuses of the relevant squares
            //Might also want this to delete any piece that has been taken in the move...
            move(*_userInput, *userInput, *moveInput);
            break;
        case 4:
            if(_bishopInput->canMove(*moveInput, board) == false) {
                cerr << "ERROR: This is an Invalid Move for a Bishop!\n" << endl;
                return;
            }
            
            if(moveInput->occupied == true) {
                if( moveInput->occupiedBy.at(1) == 'p' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wp1;
                            break;
                        case '2':
                            _takenPiece = &wp2;
                            break;
                        case '3':
                            _takenPiece = &wp3;
                            break;
                        case '4':
                            _takenPiece = &wp4;
                            break;
                        case '5':
                            _takenPiece = &wp5;
                            break;
                        case '6':
                            _takenPiece = &wp6;
                            break;
                        case '7':
                            _takenPiece = &wp7;
                            break;
                        case '8':
                            _takenPiece = &wp8;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'r' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wr1;
                            break;
                        case '2':
                            _takenPiece = &wr2;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'k') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wk1;
                            break;
                        case '2':
                            _takenPiece = &wk2;
                            break;
                    }
                } else if(moveInput->occupiedBy.at(1) == 'b') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wb1;
                            break;
                        case '2':
                            _takenPiece = &wb2;
                            break;
                    }
                } else {
                    _takenPiece = &wQUEEN;
                }
            }

            
            //This actually moves the piece to the new location and updates the statuses of the relevant squares
            //Might also want this to delete any piece that has been taken in the move...
            move(*_userInput, *userInput, *moveInput);
            break;
        case 5:
            if(_queenInput->canMove(*moveInput, board) == false) {
                cerr << "ERROR: This is an Invalid Move for a Queen!\n" << endl;
                return;
            }
            
            if(moveInput->occupied == true) {
                if( moveInput->occupiedBy.at(1) == 'p' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wp1;
                            break;
                        case '2':
                            _takenPiece = &wp2;
                            break;
                        case '3':
                            _takenPiece = &wp3;
                            break;
                        case '4':
                            _takenPiece = &wp4;
                            break;
                        case '5':
                            _takenPiece = &wp5;
                            break;
                        case '6':
                            _takenPiece = &wp6;
                            break;
                        case '7':
                            _takenPiece = &wp7;
                            break;
                        case '8':
                            _takenPiece = &wp8;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'r' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wr1;
                            break;
                        case '2':
                            _takenPiece = &wr2;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'k') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wk1;
                            break;
                        case '2':
                            _takenPiece = &wk2;
                            break;
                    }
                } else if(moveInput->occupiedBy.at(1) == 'b') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wb1;
                            break;
                        case '2':
                            _takenPiece = &wb2;
                            break;
                    }
                } else {
                    _takenPiece = &wQUEEN;
                }
            }

            
            //This actually moves the piece to the new location and updates the statuses of the relevant squares
            //Might also want this to delete any piece that has been taken in the move...
            move(*_userInput, *userInput, *moveInput);
            break;
        case 6:
            if(_kingInput->canMove(*moveInput, board) == false) {
                cerr << "ERROR: This is an Invalid Move for a King!\n" << endl;
                return;
            }
            
            if(moveInput->occupied == true) {
                if( moveInput->occupiedBy.at(1) == 'p' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wp1;
                            break;
                        case '2':
                            _takenPiece = &wp2;
                            break;
                        case '3':
                            _takenPiece = &wp3;
                            break;
                        case '4':
                            _takenPiece = &wp4;
                            break;
                        case '5':
                            _takenPiece = &wp5;
                            break;
                        case '6':
                            _takenPiece = &wp6;
                            break;
                        case '7':
                            _takenPiece = &wp7;
                            break;
                        case '8':
                            _takenPiece = &wp8;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'r' ) {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wr1;
                            break;
                        case '2':
                            _takenPiece = &wr2;
                            break;
                    }
                } else if( moveInput->occupiedBy.at(1) == 'k') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wk1;
                            break;
                        case '2':
                            _takenPiece = &wk2;
                            break;
                    }
                } else if(moveInput->occupiedBy.at(1) == 'b') {
                    switch(moveInput->occupiedBy.at(2)) {
                        case '1':
                            _takenPiece = &wb1;
                            break;
                        case '2':
                            _takenPiece = &wb2;
                            break;
                    }
                } else {
                    _takenPiece = &wQUEEN;
                }
            }

            
            //This actually moves the piece to the new location and updates the statuses of the relevant squares
            //Might also want this to delete any piece that has been taken in the move...
            move(*_userInput, *userInput, *moveInput);
            break;
    }
    
    if(blackCheck() == true) {
        cerr << "ERROR: You Are In Check!" << endl;
        cerr << "Please Try A Different Move" << endl;
        takeBackMove( *_userInput, *userInput, *_takenPiece, *moveInput);
        return;
    }
    
    
    moveNum++;
    
    

}

/*
 This move method will need to change the location of the piece being moved and update the occupied statuses of the
 original and new square locations
 */
void move(PIECE & _pieceBeingMoved, Square & _originalLocation, Square & _newLocation) {
    cout << "Hello from the move() method!" << endl;
    
    if(_newLocation.occupied == true) {
        takePiece(_newLocation);
    }
    
    //Updating the location of the Piece
    _pieceBeingMoved.setLocation(_newLocation);
    _pieceBeingMoved.setMoved();
    
    //Reset the values for the original location
    _originalLocation.occupied = false;
    _originalLocation.occupiedBy = "-";
    
    //Set the values for the new location
    _newLocation.occupied = true;
    _newLocation.occupiedBy = _pieceBeingMoved.getName();
    
    cout << "Positions updated\n" << endl;
}

void takePiece(Square & _moveLocation) {
    PIECE * _choppingBlock;
    
    switch( _moveLocation.occupiedBy.at(0)) {
        case 'w':
            if( _moveLocation.occupiedBy.at(1) == 'p' ) {
                switch(_moveLocation.occupiedBy.at(2)) {
                    case '1':
                        _choppingBlock = &wp1;
                        break;
                    case '2':
                        _choppingBlock = &wp2;
                        break;
                    case '3':
                        _choppingBlock = &wp3;
                        break;
                    case '4':
                        _choppingBlock = &wp4;
                        break;
                    case '5':
                        _choppingBlock = &wp5;
                        break;
                    case '6':
                        _choppingBlock = &wp6;
                        break;
                    case '7':
                        _choppingBlock = &wp7;
                        break;
                    case '8':
                        _choppingBlock = &wp8;
                        break;
                }
            } else if( _moveLocation.occupiedBy.at(1) == 'r' ) {
                switch(_moveLocation.occupiedBy.at(2)) {
                    case '1':
                        _choppingBlock = &wr1;
                        break;
                    case '2':
                        _choppingBlock = &wr2;
                        break;
                }
            } else if( _moveLocation.occupiedBy.at(1) == 'k') {
                switch(_moveLocation.occupiedBy.at(2)) {
                    case '1':
                        _choppingBlock = &wk1;
                        break;
                    case '2':
                        _choppingBlock = &wk2;
                        break;
                }
            } else if(_moveLocation.occupiedBy.at(1) == 'b') {
                switch(_moveLocation.occupiedBy.at(2)) {
                    case '1':
                        _choppingBlock = &wb1;
                        break;
                    case '2':
                        _choppingBlock = &wb2;
                        break;
                }
            } else {
                _choppingBlock = &wQUEEN;
                break;
            }
            break;
        case 'b':
            if( _moveLocation.occupiedBy.at(1) == 'p' ) {
                switch(_moveLocation.occupiedBy.at(2)) {
                    case '1':
                        _choppingBlock = &bp1;
                        break;
                    case '2':
                        _choppingBlock = &bp2;
                        break;
                    case '3':
                        _choppingBlock = &bp3;
                        break;
                    case '4':
                        _choppingBlock = &bp4;
                        break;
                    case '5':
                        _choppingBlock = &bp5;
                        break;
                    case '6':
                        _choppingBlock = &bp6;
                        break;
                    case '7':
                        _choppingBlock = &bp7;
                        break;
                    case '8':
                        _choppingBlock = &bp8;
                        break;
                }
            } else if( _moveLocation.occupiedBy.at(1) == 'r' ) {
                switch(_moveLocation.occupiedBy.at(2)) {
                    case '1':
                        _choppingBlock = &br1;
                        break;
                    case '2':
                        _choppingBlock = &br2;
                        break;
                }
            } else if( _moveLocation.occupiedBy.at(1) == 'k') {
                switch(_moveLocation.occupiedBy.at(2)) {
                    case '1':
                        _choppingBlock = &bk1;
                        break;
                    case '2':
                        _choppingBlock = &bk2;
                        break;
                }
            } else if(_moveLocation.occupiedBy.at(1) == 'b') {
                switch(_moveLocation.occupiedBy.at(2)) {
                    case '1':
                        _choppingBlock = &bb1;
                        break;
                    case '2':
                        _choppingBlock = &bb2;
                        break;
                }
            } else {
                _choppingBlock = &bQUEEN;
                break;
            }
            break;
    }
    
    cout << "You have taken piece " << _choppingBlock->getName() << "!" << endl;
    
    _choppingBlock->setLocation(graveYard);
    
    cout << "You fought well, soldier" << endl;
}

void takeBackMove(PIECE &_movedPiece, Square & _originalLocation, PIECE & _takenPiece, Square & _takenLocation) {
    cout << "Move Taken Back...  ";
    
    _movedPiece.setLocation(_originalLocation);
    _movedPiece.setBackMove();
    _originalLocation.occupied = true;
    _originalLocation.occupiedBy = _movedPiece.getName();
    
    if(&_takenPiece != nullptr) {
        _takenPiece.setLocation(_takenLocation);
        _takenLocation.occupiedBy = _takenPiece.getName();
        cout << "Resetting Taken Piece's Location...  ";
    }
    
    cout << "Done." << endl;
}

bool whiteCheck() {
    
    if(bp1.canTake(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(bp2.canTake(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(bp3.canTake(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(bp4.canTake(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(bp5.canTake(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(bp6.canTake(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(bp7.canTake(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(bp8.canTake(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(br1.canMove(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(br2.canMove(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(bk1.canMove(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(bk2.canMove(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(bb1.canMove(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(bb2.canMove(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    if(bQUEEN.canMove(board[wKING.getColNum()][wKING.getRow()-1], board) == true) { return true; }
    
    return false;
    
}

bool blackCheck() {
    
    if(wp1.canTake(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wp2.canTake(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wp3.canTake(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wp4.canTake(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wp5.canTake(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wp6.canTake(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wp7.canTake(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wp8.canTake(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wr1.canMove(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wr2.canMove(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wk1.canMove(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wk2.canMove(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wb1.canMove(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wb2.canMove(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    if(wQUEEN.canMove(board[bKING.getColNum()][bKING.getRow()-1], board) == true) { return true; }
    
    return false;
    
}


//Terrible CheckMate method

bool checkMate() {
    bool gameOver = false;
    
    if(whiteCheck() == true) {
        cout << "---------------------------------------------------------" << endl;
        
        for( int i = 0; i < 8; i++ ) {
            for(int j = 0; j < 8; j++) {
                PIECE * _takenPiece = nullptr;
                PIECE * _movedPiece = nullptr;
                Square * _originalLocation = nullptr;
                if(wp1.canMove(board[i][j], board) == true) {
                    _movedPiece = &wp1;
                    _originalLocation = &board[wp1.getColNum()][wp1.getRow()-1];
                    if(board[i][j].occupied == true) {
                        cout << board[i][j].location << endl;
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(wp1, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(wp1, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wp2.canMove(board[i][j], board) == true) {
                    _movedPiece = &wp2;
                    _originalLocation = &board[wp2.getColNum()][wp2.getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(wp2, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(wp2, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wp3.canMove(board[i][j], board) == true) {
                    _movedPiece = &wp3;
                    _originalLocation = &board[wp3.getColNum()][wp3.getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(wp3, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(wp3, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wp4.canMove(board[i][j], board) == true) {
                    _movedPiece = &wp4;
                    _originalLocation = &board[wp4.getColNum()][wp4.getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(wp4, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(wp4, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wp5.canMove(board[i][j], board) == true) {
                    _movedPiece = &wp5;
                    _originalLocation = &board[wp5.getColNum()][wp5.getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(wp5, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(wp5, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wp6.canMove(board[i][j], board) == true) {
                    _movedPiece = &wp6;
                    _originalLocation = &board[wp6.getColNum()][wp6.getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(wp6, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(wp6, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wp7.canMove(board[i][j], board) == true) {
                    _movedPiece = &wp7;
                    _originalLocation = &board[wp7.getColNum()][wp7.getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(wp7, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(wp7, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wp8.canMove(board[i][j], board) == true) {
                    _movedPiece = &wp8;
                    _originalLocation = &board[wp8.getColNum()][wp8.getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(wp8, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(wp8, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wr1.canMove(board[i][j], board) == true) {
                    _movedPiece = &wr1;
                    _originalLocation = &board[_movedPiece->getColNum()][_movedPiece->getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(*_movedPiece, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(*_movedPiece, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wr2.canMove(board[i][j], board) == true) {
                    _movedPiece = &wr2;
                    _originalLocation = &board[_movedPiece->getColNum()][_movedPiece->getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(*_movedPiece, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(*_movedPiece, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wk1.canMove(board[i][j], board) == true) {
                    _movedPiece = &wk1;
                    _originalLocation = &board[_movedPiece->getColNum()][_movedPiece->getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(*_movedPiece, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(*_movedPiece, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wk2.canMove(board[i][j], board) == true) {
                    _movedPiece = &wk2;
                    _originalLocation = &board[_movedPiece->getColNum()][_movedPiece->getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(*_movedPiece, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(*_movedPiece, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wb1.canMove(board[i][j], board) == true) {
                    _movedPiece = &wb1;
                    _originalLocation = &board[_movedPiece->getColNum()][_movedPiece->getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(*_movedPiece, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(*_movedPiece, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wb2.canMove(board[i][j], board) == true) {
                    _movedPiece = &wb2;
                    _originalLocation = &board[_movedPiece->getColNum()][_movedPiece->getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(*_movedPiece, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(*_movedPiece, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wQUEEN.canMove(board[i][j], board) == true) {
                    _movedPiece = &wQUEEN;
                    _originalLocation = &board[_movedPiece->getColNum()][_movedPiece->getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(*_movedPiece, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(*_movedPiece, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
                if(wKING.canMove(board[i][j], board) == true) {
                    _movedPiece = &wKING;
                    _originalLocation = &board[_movedPiece->getColNum()][_movedPiece->getRow()-1];
                    if(board[i][j].occupied == true) {
                        if( board[i][j].occupiedBy.at(1) == 'p' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bp1;
                                    break;
                                case '2':
                                    _takenPiece = &bp2;
                                    break;
                                case '3':
                                    _takenPiece = &bp3;
                                    break;
                                case '4':
                                    _takenPiece = &bp4;
                                    break;
                                case '5':
                                    _takenPiece = &bp5;
                                    break;
                                case '6':
                                    _takenPiece = &bp6;
                                    break;
                                case '7':
                                    _takenPiece = &bp7;
                                    break;
                                case '8':
                                    _takenPiece = &bp8;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'r' ) {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &br1;
                                    break;
                                case '2':
                                    _takenPiece = &br2;
                                    break;
                            }
                        } else if( board[i][j].occupiedBy.at(1) == 'k') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bk1;
                                    break;
                                case '2':
                                    _takenPiece = &bk2;
                                    break;
                            }
                        } else if(board[i][j].occupiedBy.at(1) == 'b') {
                            switch(board[i][j].occupiedBy.at(2)) {
                                case '1':
                                    _takenPiece = &bb1;
                                    break;
                                case '2':
                                    _takenPiece = &bb2;
                                    break;
                            }
                        } else {
                            _takenPiece = &bQUEEN;
                        }
                        takePiece(board[i][j]);
                    }
                    move(*_movedPiece, *_originalLocation, board[i][j]);
                    if(whiteCheck() == false) {
                        return gameOver;
                    }
                    takeBackMove(*_movedPiece, *_originalLocation, *_takenPiece, board[i][j]);
                    _takenPiece = nullptr;
                }
            }
        }
        
        gameOver = true;
        
    }
    
    // This doesn't appear to be finished
    if(blackCheck() == true) {
        
        
    }
    
    
    return gameOver;
}
 
