//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_KNIGHT_H
#define CHESSENGINE_KNIGHT_H
#include "Piece.h"

class Knight : public Piece {
public:
    //Default Constructor
    explicit Knight(const GridPoint pt, const bool color) : Piece(pt, color)
    {

    }

    void accept(Visitor& visitor) const override;
};
#endif //CHESSENGINE_KNIGHT_H