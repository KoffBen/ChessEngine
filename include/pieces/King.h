//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_KING_H
#define CHESSENGINE_KING_H
#include "Piece.h"

class King : public Piece {
public:
    //Default Constructor
    King(const Board& board, bool color);

    //getMoves
    std::list<GridPoint> getMoves(GridPoint& rhs) override;

    //clone
    Piece* clone() override;
};

#endif //CHESSENGINE_KING_H