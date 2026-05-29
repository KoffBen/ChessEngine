//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_BISHOP_H
#define CHESSENGINE_BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
public:
    //Default Constructor
    explicit Bishop(const GridPoint pt, const bool color) : Piece(pt, color)
    {

    }

    void accept(Visitor& visitor) const override;
};

#endif //CHESSENGINE_BISHOP_H