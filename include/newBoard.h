//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_NEWBOARD_H
#define CHESSENGINE_NEWBOARD_H

#include "Piece.h"

//Called NewBoard for the time being because it's replacing Board but I want to leave that code intact for smooth transition
class NewBoard
{
public:
    NewBoard() = default;

    //Deep Delete -- wait we're deep deleting these twice. Hmm. Okay we'll delete from the composite when we kill the interface
    ~NewBoard() = default;

    void defaultSetup();

    //IMPORTANT: This is to be adapted with UCI Specs
    void givenSetup();
private:
    Piece* mBoard[8][8] = {};

    double eval;
};

#endif //CHESSENGINE_NEWBOARD_H
