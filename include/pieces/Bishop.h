//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_BISHOP_H
#define CHESSENGINE_BISHOP_H
#include "Piece.h"

class Bishop : public Piece{
public:
    //Default Constructor
    Bishop(const Board* const board, const bool color) : Piece(board, 3, color, 'B') {

    }

    //getMoves
    std::list<GridPoint> getMoves(GridPoint& rhs) override;

    //clone
    Piece* clone() override;
};

#endif //CHESSENGINE_BISHOP_H