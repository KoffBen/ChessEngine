//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_BISHOP_H
#define CHESSENGINE_BISHOP_H
#include "Piece.h"

class Bishop : public Piece{
public:
    Bishop(GridPoint loc, bool color) : mPoints(3), mLoc(loc), mColor(color), mChar('B'), mMoves() {

    }

    std::stack<GridPoint> getPotentialMoves() override {
        return mMoves;
    }

    int getPoints() override {return mPoints;}

    GridPoint getLoc() override {return mLoc;}

    void setLoc(const GridPoint& rhs) override {
        mLoc.x(rhs.x());
        mLoc.y(rhs.y());
    };

    bool getColor() override {return mColor;}

    char getChar() override {return mChar;}

private:
    int mPoints;

    GridPoint mLoc;

    bool mColor;

    char mChar;

    stack<GridPoint> mMoves;

    void findMoves() {

    }
};

#endif //CHESSENGINE_BISHOP_H