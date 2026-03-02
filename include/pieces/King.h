//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_KING_H
#define CHESSENGINE_KING_H
#include "Piece.h"

class King : public Piece {
public:
    King(const Board& board, GridPoint& loc, const bool color) : Piece(board, loc, 0,
        color,'K') {

    }

private:
    void findMoves() override;
};

#endif //CHESSENGINE_KING_H