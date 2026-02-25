//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_SQUARE_H
#define CHESSENGINE_SQUARE_H
#include "Piece.h"

class Square {

public:
    //Default Constructor
    Square() : mPiece(), mAttacked(false), mOccupied(false), mColor(false), mCoord(-1,-1) {

    }
    //Destructor
    ~Square() = default;

    //Copy constructor
    Square(const Square& rhs);

    //Copy Operator
    Square& operator=(const Square& rhs);

    //Alternate Constructor
    Square(Piece* piece, const bool& attacked, const bool& occupied, const bool& color, const
            GridPoint& coord) : mPiece
        (piece), mAttacked(attacked), mOccupied(occupied), mColor(color), mCoord(coord) {

    }

    Piece* getPiece();
    void setPiece(Piece* rhs);

    bool isAttacked();
    void setAttacked(const bool& rhs);

    bool isOccupied();
    void setOccupied(const bool& rhs);

    bool getColor();
    void setColor(const bool& rhs);

    GridPoint getCoord();


private:
    /**
     * The piece on the square, null if empty
     */
    Piece* mPiece;

    /**
     *True if the square is under attack, false otherwise
     */
    bool mAttacked;

    /**
     *True if the square is occupied, false otherwise
     */
    bool mOccupied;

    /**
     *True if the square is occupied by white, false otherwise
     */
    bool mColor;

    /**
     *The coordinate associated with this square
     */
    GridPoint mCoord;


};

#endif //CHESSENGINE_SQUARE_H