//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_BOARD_H
#define CHESSENGINE_BOARD_H

#include "Square.h"

class Board {
public:
    //Default Constructor
    Board() : mSquare(new Square[8][8]), mColor(true), mEval(0) {

    }
    //Copy Constructor
    Board(const Board& rhs);
    //Copy Operator
    Board& operator=(const Board& rhs);
    //Destructor
    ~Board();


private:
    /**
     * The squares that make up the board
     */
    Square mSquare[][];

    /**
     * Is this board from white's perspective
     */
    bool mColor;
    /**
     * The evaluation of the present state of the board
     */
    int mEval;
};

#endif //CHESSENGINE_BOARD_H