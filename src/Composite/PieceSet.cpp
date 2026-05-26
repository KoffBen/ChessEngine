//
// Created by benja on 5/24/2026.
//
#include "Composite/PieceSet.h"

bool PieceSet::addPiece(Piece* piece, bool color)
{
    if (color)
    {
        return white.addPiece(piece);
    }
    return black.addPiece(piece);
}

bool PieceSet::removePiece(Piece* piece, bool color)
{
    if (color)
    {
        return white.removePiece(piece);
    }
    return black.removePiece(piece);
}

bool PieceSet::visitSet(Visitor& visitor, bool color)
{
    if (color)
    {
        return white.visitColor(visitor);
    }
    return black.visitColor(visitor);
}
