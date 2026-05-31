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
    explicit MovePiece(Context* context, Piece* piece, const GridPoint& endLoc) : Command(context), mPiece(piece),
                                                                        startLoc(piece->getPos()), endLoc(endLoc),
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

    [[nodiscard]] bool checkValidMove() const;
    [[nodiscard]] bool checkValidForPiece() const;

    [[nodiscard]] bool checkRook() const;

    [[nodiscard]] bool checkBishop() const;
    [[nodiscard]] bool checkHelper(const GridPoint& adder) const;

    [[nodiscard]] bool checkPawn() const;
};

#endif //CHESSENGINE_MOVEPIECE_H
