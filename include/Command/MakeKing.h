//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_MAKEKING_H
#define CHESSENGINE_MAKEKING_H
#include "Command.h"
#include "../NewGridPoint.h"

class MakeKing : Command
{
public:
    MakeKing(Context* context, const NewGridPoint& pt, const bool color) : Command(context), mPt(pt), mColor(color)
    {

    }
    //This Command needs to make a king piece, put it in the desired location on the board
    bool execute() override;
private:
    NewGridPoint mPt;
    bool mColor;
};
#endif //CHESSENGINE_MAKEKING_H
