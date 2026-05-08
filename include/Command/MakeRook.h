//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_MAKEROOK_H
#define CHESSENGINE_MAKEROOK_H
#include "Command.h"
#include "../NewGridPoint.h"

class MakeRook : Command
{
public:
    MakeRook(Context* context, const NewGridPoint& pt, const bool color) : Command(context), mPt(pt), mColor(color)
    {

    }
    //This Command needs to make a rook piece, put it in the desired location on the board
    bool execute() override;
private:
    NewGridPoint mPt;
    bool mColor;
};
#endif //CHESSENGINE_MAKEROOK_H
