//
// Created by benja on 5/26/2026.
//

#ifndef CHESSENGINE_FACTORY_H
#define CHESSENGINE_FACTORY_H
#include <string>

class Command;
class Context;
class GridPoint;
class Piece;

class CommandFactory
{
public:
    explicit CommandFactory(Context* context) : mContext(context)
    {

    }

    Command* makeCommand(char pieceType, const GridPoint& pos, bool color);

    Command* makeCommand(char pieceType, const GridPoint& pos, bool color, Piece* piece);

    Command* makeMoveCommand(const std::string& move);
private:
    Context* mContext;

    bool checkMoveString(const std::string& checkString) const;
};

#endif //CHESSENGINE_FACTORY_H
