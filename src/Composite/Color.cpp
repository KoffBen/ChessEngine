//
// Created by benja on 5/24/2026.
//
#include "Composite/Color.h"

Color::~Color()
{
    std::for_each(pieces.begin(), pieces.end(), [](Piece* tmp) {delete tmp;});
}

bool Color::addPiece(Piece* piece)
{
    return pieces.insert(piece).second;
}

bool Color::removePiece(Piece* piece)
{
    return pieces.erase(piece);
}

bool Color::visitColor(Visitor& visitor)
{
    std::for_each(pieces.begin(), pieces.end(), [&visitor](Piece* tmp)
    {
        tmp->accept(visitor);
    });
    return true;
}
