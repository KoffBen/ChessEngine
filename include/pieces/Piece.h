//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_PIECE_H
#define CHESSENGINE_PIECE_H

#include <list>

#include "NewGridPoint.h"
#include "../GridPoint.h"
#include "Visitor/Visitor.h"

class Board;

class Piece {

public:
    Piece(NewGridPoint pt) : mPt(pt)
    {

    }

    virtual void accept(Visitor& visitor) const = 0;
private:
    NewGridPoint mPt;
};

#endif //CHESSENGINE_PIECE_H