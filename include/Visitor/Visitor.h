//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_VISITOR_H
#define CHESSENGINE_VISITOR_H

class Bishop;
class Rook;
class Knight;
class King;
class Queen;
class Pawn;

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
