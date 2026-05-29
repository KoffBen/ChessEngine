//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_KING_H
#define CHESSENGINE_KING_H
#include "Piece.h"

class King : public Piece {
public:
    //Default Constructor
    explicit King(const GridPoint pt, const bool color) : Piece(pt, color)
    {

    }

    void accept(Visitor& visitor) const override;
};

#endif //CHESSENGINE_KING_H