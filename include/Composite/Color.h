//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_COLOR_H
#define CHESSENGINE_COLOR_H
#include "../Piece.h"


class Color
{
public:
    //Constructor to initialize the array
    Color();

    //Deep Destruction
    ~Color();

    void addPiece(const Piece* piece);


private:
    Piece* pieces[];
};

#endif //CHESSENGINE_COLOR_H
