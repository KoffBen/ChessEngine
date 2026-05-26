//
// Created by benja on 5/24/2026.
//
#include "Composite/Color.h"

Color::~Color()
{
    std::for_each(pieces, pieces + 24, [](Piece* tmp) {delete tmp;});
}

void Color::addPiece(const Piece* piece)
{
    pieces.insert()
}

Piece* Color::removePiece(const NewGridPoint& pt)
{

}
