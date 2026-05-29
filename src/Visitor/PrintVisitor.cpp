//
// Created by benja on 5/27/2026.
//
#include "Visitor/PrintVisitor.h"

#include <iostream>

#include "Board.h"
#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"

void PrintVisitor::visit(const Rook& rook) const
{
    if (rook.getColor())
    {
        os << "r";
    } else
    {
        os << "R";
    }
}

void PrintVisitor::visit(const Knight& knight) const
{
    if (knight.getColor())
    {
        os << "n";
    } else
    {
        os << "N";
    }
}

void PrintVisitor::visit(const Bishop& bishop) const
{
    if (bishop.getColor())
    {
        os << "b";
    } else
    {
        os << "B";
    }
}

void PrintVisitor::visit(const Queen& queen) const
{
    if (queen.getColor())
    {
        os << "q";
    } else
    {
        os << "Q";
    }
}

void PrintVisitor::visit(const King& king) const
{
    if (king.getColor())
    {
        os << "k";
    } else
    {
        os << "K";
    }
}

void PrintVisitor::visit(const Pawn& pawn) const
{
    if (pawn.getColor())
    {
        os << "p";
    } else
    {
        os << "P";
    }
}

void PrintVisitor::visit(const Board& board) const
{
    auto newVisit = PrintVisitor(os);
    auto pt = GridPoint(0, 7);
    os << "\n" << "---------------------------------" << "\n";
    os << "| ";
    while (pt.y >= 0)
    {
        Piece* tmp = board.getPiece(pt);
        if (tmp != nullptr)
        {
            tmp->accept(newVisit);
        } else
        {
            os << " ";
        }
        if (pt.x < 7) os << " | ";
        ++pt.x;
        if (pt.x == 8)
        {
            pt.x = 0;
            --pt.y;
            os << " |";
            os << "\n" << "---------------------------------" << "\n";
            if (pt.y >= 0) os << "| ";
        }
    }
}