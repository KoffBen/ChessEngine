//
// Created by benja on 5/27/2026.
//
#include "Visitor/PrintVisitor.h"

#include <iostream>

#include "NewBoard.h"
#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"

void Visitor::visit(const Rook& rook) const
{
    if (rook.getColor())
    {
        std::cout<<"r";
    } else
    {
        std::cout<<"R";
    }
}

void Visitor::visit(const Knight& knight) const
{
    if (knight.getColor())
    {
        std::cout<<"n";
    } else
    {
        std::cout<<"N";
    }
}

void Visitor::visit(const Bishop& bishop) const
{
    if (bishop.getColor())
    {
        std::cout<<"b";
    } else
    {
        std::cout<<"B";
    }
}

void Visitor::visit(const Queen& queen) const
{
    if (queen.getColor())
    {
        std::cout<<"q";
    } else
    {
        std::cout<<"Q";
    }
}

void Visitor::visit(const King& king) const
{
    if (king.getColor())
    {
        std::cout<<"k";
    } else
    {
        std::cout<<"K";
    }
}

void Visitor::visit(const Pawn& pawn) const
{
    if (pawn.getColor())
    {
        std::cout<<"p";
    } else
    {
        std::cout<<"P";
    }
}

void Visitor::visit(const NewBoard& board) const
{
    NewGridPoint pt = NewGridPoint(0, 7);
    while (pt.y >= 0)
    {
        visit(*board.getPiece(pt));
    }
}