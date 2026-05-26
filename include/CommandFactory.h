//
// Created by benja on 5/26/2026.
//

#ifndef CHESSENGINE_FACTORY_H
#define CHESSENGINE_FACTORY_H
#include "Core/Context.h"
#include "Command/MakePiece.h"

class CommandFactory
{
public:
    CommandFactory(Context& context) : mContext(context)
    {

    }

    Command* makeCommand(char pieceType, NewGridPoint& pos, bool color);
private:
    Context mContext;
};

#endif //CHESSENGINE_FACTORY_H
