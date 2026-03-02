//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_BISHOP_H
#define CHESSENGINE_BISHOP_H
#include "Piece.h"

class Bishop : public Piece{
public:
    Bishop(const Board& board, GridPoint& loc, const bool color) : Piece(board, loc, 3,
        color,'B') {

    }

private:
    void findMoves() override;
};

#endif //CHESSENGINE_BISHOP_H