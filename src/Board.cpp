//
// Created by benja on 2/25/2026.
//

#include "Board.h"


Board::Board() : mSquares(), mPieces(new Piece*[32]), mColor(true), mEval(0) {
    resetBoard();
}

Board::Board(const Board& rhs) : mSquares(), mPieces(new Piece*[32]), mColor(rhs.mColor), mEval(rhs.mEval) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            mSquares[i][j] = rhs.mSquares[i][j];
        }
    }

    for (int i = 0; i < 32; ++i) {
        mPieces[i] = rhs.mPieces[i]->clone();
    }
}

Board::~Board() {
    delete[] mPieces;
}

bool Board::isOnBoard(const GridPoint& rhs) const {
    return rhs.x() < 8 && rhs.x() >= 0 && rhs.y() < 8 && rhs.y() >= 0;
}

bool Board::isOnBoard(const int x, const int y) const {
    return isOnBoard(GridPoint(x, y));
}

bool Board::isEligible(const GridPoint& rhs) const {
    return isOnBoard(rhs) && (!mSquares[rhs.x()][rhs.y()].isOccupied() || mSquares[rhs.x()][rhs
        .y()].getPiece()->getColor() != mColor);
}

bool Board::getColor() const {
    return mColor;
}

void Board::setColor(bool rhs) {
    mColor = rhs;
}

double Board::getEval() {
    calcEval();
    return mEval;
}

void Board::calcEval() {
    mEval = 0.0;;
}

std::string Board::toString() {
    //Build this later
    return "";
}

const Square& Board::getSquare(const GridPoint& rhs) {
    return mSquares[rhs.x()][rhs.y()];
}

void Board::resetPieces() {
    for (int i = 0; i < 32; ++i) {
        /*switch (i) {
            case 0:
            case 7:
                //I CAN'T DO THIS UNTIL I MAKE ALL THE PIECES FML
                //mPieces[i] = new Rook*
        }
        */
    }
}

void Board::resetBoard() {
    mColor = true;
    mEval = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i == 0 || i == 6) {

            }
        }
    }
}