//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_PRINTVISITOR_H
#define CHESSENGINE_PRINTVISITOR_H
#include "Visitor.h"

class PrintVisitor : Visitor
{
public:
    void visit(const Rook& rook) const override;

    void visit(const Knight& knight) const override;

    void visit(const Bishop& bishop) const override;

    void visit(const Queen& queen) const override;

    void visit(const King& king) const override;

    void visit(const Pawn& pawn) const override;

    void visit(const NewBoard& board) const override;
};

#endif //CHESSENGINE_PRINTVISITOR_H
