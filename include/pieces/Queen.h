//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_QUEEN_H
#define CHESSENGINE_QUEEN_H
#include "Piece.h"

class Queen : public Piece {
public:
    //Default Constructor
    explicit Queen(const NewGridPoint pt) : Piece(pt)
    {

    }

    void accept(Visitor& visitor) const override;
};
#endif //CHESSENGINE_QUEEN_H