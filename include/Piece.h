//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_PIECE_H
#define CHESSENGINE_PIECE_H
#include "GridPoint.h"
#include <stack>

class Piece {

public:
    //Constructor
    Piece() = default;

    virtual ~Piece() = default;

    virtual std::stack<GridPoint> getPotentialMoves() = 0;

    virtual int getPoints() = 0;

    virtual GridPoint getLoc() = 0;

    virtual void setLoc(const GridPoint& rhs) = 0;

    virtual bool getColor() = 0;

    virtual char getChar() = 0;

};

#endif //CHESSENGINE_PIECE_H