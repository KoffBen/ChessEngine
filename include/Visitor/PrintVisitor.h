//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_PRINTVISITOR_H
#define CHESSENGINE_PRINTVISITOR_H
#include <iosfwd>

#include "Visitor.h"

class PrintVisitor : public Visitor
{
public:
    PrintVisitor(std::ostream& os) : os(os)
    {

    }

    void visit(const Rook& rook) const override;

    void visit(const Knight& knight) const override;

    void visit(const Bishop& bishop) const override;

    void visit(const Queen& queen) const override;

    void visit(const King& king) const override;

    void visit(const Pawn& pawn) const override;

    void visit(const NewBoard& board) const override;
private:
    std::ostream& os;
};

#endif //CHESSENGINE_PRINTVISITOR_H
