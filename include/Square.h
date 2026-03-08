//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_SQUARE_H
#define CHESSENGINE_SQUARE_H
#include "Piece.h"

class Square {

public:
    //Default Constructor
    Square();
    //Destructor
    //Reminder to delete the pieces when the square deletes
    //ACTUAL: Make sure to decrement the square count when it's deleted
    ~Square();

    //Copy constructor
    Square(const Square& rhs);

    //Alternate Constructor
    Square(Piece* piece);

    //Copy Operator
    Square& operator=(const Square& rhs);

    [[nodiscard]] Piece* getPiece() const;

    void setPiece(Piece* rhs);

    Piece* movePiece();

    [[nodiscard]] bool isOccupied() const;

private:
    /**
     * The piece on the square, null if empty
     */
    Piece* mPiece;

    /**
     *True if the square is occupied, false otherwise
     */
    bool mOccupied;

    static int squareCount;
};

#endif //CHESSENGINE_SQUARE_H