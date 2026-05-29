//
// Created by benja on 5/26/2026.
//

#ifndef CHESSENGINE_FACTORY_H
#define CHESSENGINE_FACTORY_H

class Command;
class Context;
class GridPoint;

class CommandFactory
{
public:
    explicit CommandFactory(Context* context) : mContext(context)
    {

    }

    Command* makeCommand(char pieceType, const GridPoint& pos, bool color);
private:
    Context* mContext;
};

#endif //CHESSENGINE_FACTORY_H
