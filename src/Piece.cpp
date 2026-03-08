//
// Created by benja on 3/8/2026.
//

#include "Board.h"

Piece::Piece(const Board& board, const int points, const bool color, const char newChar) :
    mBoard(&board), mPoints(points), mColor(color), mChar(newChar) {
}

[[nodiscard]] int Piece::getPoints() const {
    return mPoints;
}

[[nodiscard]] bool Piece::getColor() const {
    return mColor;
}

[[nodiscard]] char Piece::getChar() const {
    return mChar;
}

int Piece::getEligibility(int x, int y) const {
    if (const auto currGrid = GridPoint(x, y); mBoard->isEligible(currGrid)) {
        if (mBoard->getSquare(currGrid).isOccupied()) {
            return 1;
        }
        return 2;
    }
    return 0;
}

bool Piece::getEligibility2(int x, int y) const {
    return mBoard->isEligible(GridPoint(x, y));
}