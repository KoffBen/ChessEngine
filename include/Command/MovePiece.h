//
// Created by benja on 5/28/2026.
//

#ifndef CHESSENGINE_MOVEPIECE_H
#define CHESSENGINE_MOVEPIECE_H

#include "Command/Command.h"

class MovePiece : public Command
{
public:
    explicit MovePiece(Context* context, Piece* piece, NewGridPoint& pt) : Command(context), mPiece(piece), endLoc(pt)
    {

    }

    bool execute() override;

    bool undo() override;

private:
    Piece* mPiece;
    NewGridPoint endLoc;
    bool checkValidMove();
};

#endif //CHESSENGINE_MOVEPIECE_H
