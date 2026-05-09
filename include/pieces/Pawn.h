//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_PAWN_H
#define CHESSENGINE_PAWN_H
#include "Piece.h"

class Pawn : public Piece {
public:
    //Default Constructor
    explicit Pawn(const NewGridPoint pt) : Piece(pt)
    {

    }

    void accept(Visitor& visitor) const override;
};
#endif //CHESSENGINE_PAWN_H