//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_PIECE_H
#define CHESSENGINE_PIECE_H

#include <list>
#include "GridPoint.h"

class Board;

class Piece {

public:
    //Constructor, to be used by the children
    Piece(const Board& board, int points, bool color, char newChar);

    virtual ~Piece() = default;

    //Should be overridden
    virtual std::list<GridPoint> getMoves(GridPoint& rhs) = 0;

    [[nodiscard]] int getPoints() const;

    [[nodiscard]] bool getColor() const;

    [[nodiscard]] char getChar() const;

    //Intention is to be overridden s.t. each piece will clone one of its own pieces
    virtual Piece* clone() = 0;

protected:
    const Board* const mBoard;
    std::list<GridPoint> mMoves;

    [[nodiscard]] int getEligibility(int x, int y) const;

    [[nodiscard]] bool getEligibility2(int x, int y) const;
private:
    int mPoints;

    bool mColor;

    char mChar;
};

#endif //CHESSENGINE_PIECE_H