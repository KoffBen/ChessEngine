//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_QUEEN_H
#define CHESSENGINE_QUEEN_H
#include "Piece.h"

class Queen : public Piece {
public:
    //Default Constructor
    explicit Queen(const GridPoint pt, const bool color) : Piece(pt, color)
    {

    }

    void accept(Visitor& visitor) const override;
};
#endif //CHESSENGINE_QUEEN_H