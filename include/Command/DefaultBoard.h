//
// Created by benja on 5/17/2026.
//

#ifndef CHESSENGINE_DEFAULTBOARD_H
#define CHESSENGINE_DEFAULTBOARD_H
#include "Command.h"

class DefaultBoard : Command
{
public:
    explicit DefaultBoard(Context* context) : Command(context)
    {

    }
    bool execute() override;
};

#endif //CHESSENGINE_DEFAULTBOARD_H
