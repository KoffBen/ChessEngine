//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_MAKEKNIGHT_H
#define CHESSENGINE_MAKEKNIGHT_H
#include "Command.h"
#include "../NewGridPoint.h"

class MakeKnight : Command
{
public:
    MakeKnight(Context* context, const NewGridPoint& pt, const bool color) : Command(context), mPt(pt), mColor(color)
    {

    }
    //This Command needs to make a knight piece, put it in the desired location on the board
    bool execute() override;
private:
    NewGridPoint mPt;
    bool mColor;
};
#endif //CHESSENGINE_MAKEKNIGHT_H
