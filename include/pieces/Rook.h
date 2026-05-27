//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_ROOK_H
#define CHESSENGINE_ROOK_H
#include "Piece.h"

class Rook : public Piece {
public:
    //Default Constructor
    explicit Rook(const NewGridPoint pt, const bool color) : Piece(pt, color)
    {

    }

    void accept(Visitor& visitor) const override;
};
#endif //CHESSENGINE_ROOK_H