//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_MAKEQUEEN_H
#define CHESSENGINE_MAKEQUEEN_H
#include "Command.h"
#include "../NewGridPoint.h"

class MakeQueen : Command
{
public:
    MakeQueen(Context* context, const NewGridPoint& pt, const bool color) : Command(context), mPt(pt), mColor(color)
    {

    }
    //This Command needs to make a queen piece, put it in the desired location on the board
    bool execute() override;
private:
    NewGridPoint mPt;
    bool mColor;
};
#endif //CHESSENGINE_MAKEQUEEN_H
