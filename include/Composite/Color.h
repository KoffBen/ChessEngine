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
    Color() = default;

    //Deep Destruction
    ~Color();

    bool addPiece(Piece* piece);

    bool removePiece(Piece* piece);

    bool visitColor(Visitor& visitor);

private:
    std::set<Piece*> pieces;
};

#endif //CHESSENGINE_COLOR_H
