//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_COLOR_H
#define CHESSENGINE_COLOR_H
#include <algorithm>
#include <set>

#include "../pieces/Piece.h"


class Color
{
public:
    //Constructor to initialize the array
    Color() : pieces(), index(0)
    {

    }

    //Deep Destruction
    ~Color();

    void addPiece(const Piece* piece);

    Piece* removePiece(const NewGridPoint& pt);

private:
    std::set<int, Piece*> pieces;
};

#endif //CHESSENGINE_COLOR_H
