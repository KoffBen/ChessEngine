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
    ('B'), mMoves(), mBoard(board) {

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

    std::stack<GridPoint> mMoves;

    const Board mBoard;

    void findMoves() {
        bool ignore[] = {false, false, false, false};
        GridPoint tmp = mLoc;

        for (int i = 1; i < 8; i++) {
            for (int j = 0; j < 4; j++) {
                if (!ignore[j]) {
                    switch (j) {
                        case 0:

                    }
                }
            }
        }
    }
};

#endif //CHESSENGINE_BISHOP_H