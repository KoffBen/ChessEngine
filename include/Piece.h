//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_PIECE_H
#define CHESSENGINE_PIECE_H

#include <list>
#include <string>
#include "Board.h"
#include "GridPoint.h"

class Piece {

public:
    //Constructor, to be used by the children
    Piece(const Board* const board, const int points, const bool color, const char newChar) :
    mBoard(board), mPoints(points), mColor(color), mChar(newChar) {
    }

    virtual ~Piece() = default;

    //Should be overridden
    virtual std::list<GridPoint> getMoves(GridPoint& rhs) = 0;

    [[nodiscard]] int getPoints() const {
        return mPoints;
    }

    [[nodiscard]] bool getColor() const {
        return mColor;
    }

    [[nodiscard]] char getChar() const {
        return mChar;
    }

    //Intention is to be overridden s.t. each piece will clone one of its own pieces
    virtual Piece* clone() = 0;

protected:
    const Board* const mBoard;
    std::list<GridPoint> mMoves;

    int getEligibility(int x, int y) {
        if (auto currGrid = GridPoint(x, y); mBoard->isEligible(currGrid)) {
            if (mBoard->getSquare(currGrid).isOccupied()) {
                return 1;
            }
            return 2;
        }
        return 0;
    }

private:
    int mPoints;

    bool mColor;

    char mChar;
};

#endif //CHESSENGINE_PIECE_H