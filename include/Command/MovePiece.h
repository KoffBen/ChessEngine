//
// Created by benja on 5/28/2026.
//

#ifndef CHESSENGINE_MOVEPIECE_H
#define CHESSENGINE_MOVEPIECE_H

#include "Command/Command.h"
#include "PassKey/PassKey.h"

class MovePiece : public Command
{
public:
    explicit MovePiece(Context* context, Piece* piece, GridPoint& pt) : Command(context), mPiece(piece),
                                                                        startLoc(piece->getPos()), endLoc(pt),
                                                                           makeOccPiece(nullptr)
    {
    }

    bool execute() override;

    bool undo() override;

private:
    Piece* mPiece;
    GridPoint startLoc;
    GridPoint endLoc;
    Command* makeOccPiece;
    PassKey key = PassKey();
    bool checkValidMove();
};

#endif //CHESSENGINE_MOVEPIECE_H
