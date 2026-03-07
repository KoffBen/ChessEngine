//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_SQUARE_H
#define CHESSENGINE_SQUARE_H
#include "Piece.h"

class Square {

public:
    //Default Constructor
    Square() : mPiece(), mOccupied(false){

    }
    //Destructor
    //Reminder to delete the pieces when the square deletes
    ~Square();

    //Copy constructor
    Square(const Square& rhs);

    //Alternate Constructor
    Square(Piece* piece) : mPiece(piece), mOccupied(true);

    //Copy Operator
    Square& operator=(const Square& rhs) {
        mPiece = rhs.mPiece->clone();
        mOccupied = rhs.mOccupied;
        return *this;
    }


    [[nodiscard]] Piece* getPiece() const {
        return mPiece;
    }
    void setPiece(Piece* rhs) {
        //Was worried about leaking memory here but because the piece is held in an array on the
        //board we will destroy it from there
        mPiece = rhs;
    }

    Piece* movePiece() {
        Piece* tmp = mPiece;
        mPiece = nullptr;
        mOccupied = false;
        return tmp;
    }

    [[nodiscard]] bool isOccupied() const {
        return mPiece != nullptr;
    }

private:
    /**
     * The piece on the square, null if empty
     */
    Piece* mPiece;

    /**
     *True if the square is occupied, false otherwise
     */
    bool mOccupied;

};

#endif //CHESSENGINE_SQUARE_H