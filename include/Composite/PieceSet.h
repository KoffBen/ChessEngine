//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_BOARD_H
#define CHESSENGINE_BOARD_H
#include "Color.h"
//My thought here is that we'll reorganize the whole structure into a tree. Board contains two sides, which each contain
//pieces. The pieces take in visitors and have composite characteristics
class PieceSet
{
public:
    //Constructor to initialize the colors, not putting anything in
    PieceSet() = default;

    //Deep Destruction will be triggered once it leaves the scope as the colors have an implemented dd
    ~PieceSet() = default;

    //Adding pieces to the composite -- this actually resembles more of a mini interpreter
    bool addPiece(Piece* piece, bool color);

    bool removePiece(Piece* piece, bool color);

    bool visitSet(Visitor& visitor, bool color);

private:
    Color black;
    Color white;
};

#endif //CHESSENGINE_BOARD_H
