//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_PIECE_H
#define CHESSENGINE_PIECE_H

#include <list>

#include "Board.h"
#include "GridPoint.h"

class Piece {

public:
    //Constructor
    Piece(const Board& board, GridPoint& loc, const int points, const bool color, const char
        name) : mBoard(&board), mLoc(&loc), mPoints(points), mColor(color), mChar(name) {

    }

    virtual ~Piece() = default;

    std::list<GridPoint>& getPotentialMoves() {
        mMoves.clear();
        findMoves();
        return mMoves;
    }

    int getPoints() {
        return mPoints;
    }

    GridPoint* getLoc() {
        return mLoc;
    }

    void setLoc(const GridPoint& rhs) {
        mLoc->x(rhs.x());
        mLoc->y(rhs.y());
    }

    bool getColor() {
        return mColor;
    }

    char getChar() {
        return mChar;
    }

protected:

    const Board* mBoard;

    GridPoint* mLoc;

private:
    int mPoints;

    bool mColor;

    char mChar;

    std::list<GridPoint> mMoves;

    virtual void findMoves() = 0;
};

#endif //CHESSENGINE_PIECE_H