//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_PAWN_H
#define CHESSENGINE_PAWN_H
#include "Piece.h"

class Pawn : public Piece {
public:
    //Default Constructor
    explicit Pawn(const GridPoint pt, const bool color) : Piece(pt, color)
    {

    }

    void accept(Visitor& visitor) const override;
};
#endif //CHESSENGINE_PAWN_H