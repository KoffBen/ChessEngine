//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_BISHOP_H
#define CHESSENGINE_BISHOP_H
#include "Piece.h"
#include "Board.h"

class Bishop : public Piece{
public:
    Bishop(const GridPoint& loc, bool color, const Board& board) : mPoints(3), mLoc(loc), mColor
    (color), mChar
    ('B'), mBoard(board) {

    }

    std::stack<GridPoint> getPotentialMoves() override {
        mMoves.

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

    bool mColor;

    char mChar;


    const Board mBoard;

    GridPoint mLoc;

    std::stack<GridPoint> mMoves;

    void findMoves();
};

#endif //CHESSENGINE_BISHOP_H