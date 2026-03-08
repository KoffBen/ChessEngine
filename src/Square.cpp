//
// Created by benja on 3/8/2026.
//

#include "Square.h"

int Square::squareCount = 0;

Square::Square() : mPiece(), mOccupied(false){
    ++squareCount;
}

Square::~Square() {
    squareCount--;
    delete mPiece;
}

//Copy constructor
Square::Square(const Square& rhs) {
    mPiece = rhs.mPiece->clone();
    mOccupied = rhs.mOccupied;
    ++squareCount;
}

//Alternate Constructor
Square::Square(Piece* piece) : mPiece(piece), mOccupied(true) {

}

//Copy Operator
Square& Square::operator=(const Square& rhs) {
    mPiece = rhs.mPiece->clone();
    mOccupied = rhs.mOccupied;
    return *this;
}


[[nodiscard]] Piece* Square::getPiece() const {
    return mPiece;
}
void Square::setPiece(Piece* rhs) {
    //Was worried about leaking memory here but because the piece is held in an array on the
    //board we will destroy it from there
    mPiece = rhs;
}

Piece* Square::movePiece() {
    Piece* tmp = mPiece;
    mPiece = nullptr;
    mOccupied = false;
    return tmp;
}

[[nodiscard]] bool Square::isOccupied() const {
    return mPiece != nullptr;
}
