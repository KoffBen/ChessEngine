//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_VISITOR_H
#define CHESSENGINE_VISITOR_H
#include "../pieces/Rook.h"
#include "../pieces/Knight.h"
#include "../pieces/Bishop.h"
#include "../pieces/Queen.h"
#include "../pieces/King.h"
#include "../pieces/Pawn.h"

class Visitor
{
public:
    Visitor() = default;

    virtual ~Visitor() = default;

    virtual void visit(const Rook& rook) const = 0;

    virtual void visit(const Knight& knight) const = 0;

    virtual void visit(const Bishop& bishop) const = 0;

    virtual void visit(const Queen& queen) const = 0;

    virtual void visit(const King& king) const = 0;

    virtual void visit(const Pawn& pawn) const = 0;
};

#endif //CHESSENGINE_VISITOR_H
