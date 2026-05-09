//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_KNIGHT_H
#define CHESSENGINE_KNIGHT_H
#include "Piece.h"

class Knight : public Piece {
public:
    //Default Constructor
    explicit Knight(const NewGridPoint pt) : Piece(pt)
    {

    }

    void accept(Visitor& visitor) const override;
};
#endif //CHESSENGINE_KNIGHT_H