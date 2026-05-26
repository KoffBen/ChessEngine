//
// Created by benja on 5/18/2026.
//

#ifndef CHESSENGINE_MAKEPIECE_H
#define CHESSENGINE_MAKEPIECE_H
#include "Command.h"
#include "../NewGridPoint.h"

template <typename PieceType>
class MakePiece : Command
{
public:
    MakePiece(Context* context, const NewGridPoint& pt, const bool color) : Command(context), mPt(pt), mColor(color)
    {

    }
    //This Command needs to make a rook piece, put it in the desired location on the board
    bool execute() override
    {
        auto* mPiece = new PieceType(mPt);
        mContext->mBoard->addPiece(mPiece);
        mContext->mSet->addPiece(mPiece, mColor);
        return true;
    }

    bool undo() override
    {
        Piece* tmpPiece = mContext->mSet->removePiece(mPt, mColor);
        if (tmpPiece == nullptr)
        {
            return false;
        }
        mContext->mBoard->removePiece(tmpPiece->getPos());
        delete tmpPiece;
        return true;
    }
private:
    NewGridPoint mPt;
    bool mColor;
};

#endif //CHESSENGINE_MAKEPIECE_H
