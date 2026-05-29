//
// Created by benja on 5/18/2026.
//

#ifndef CHESSENGINE_MAKEPIECE_H
#define CHESSENGINE_MAKEPIECE_H
#include "Command.h"
#include "../GridPoint.h"
#include "Board.h"
#include "pieces/Rook.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Queen.h"
#include "pieces/King.h"
#include "pieces/Pawn.h"

template <typename PieceType>
class MakePiece : public Command {
public:
    MakePiece(Context* context, const GridPoint& pt, const bool color) : Command(context), mPt(pt), mColor(color),
                                                                            mPiece(nullptr)
    {
    }

    //This Command needs to make a rook piece, put it in the desired location on the board
    bool execute() override
    {
        mPiece = new PieceType(mPt, mColor);
        if (!mContext->mBoard->addPiece(mPiece))
        {
            return false;
        }
        if (!mContext->mSet->addPiece(mPiece, mColor))
        {
            return false;
        }
        return true;
    }

    bool undo() override
    {
        if (mPiece == nullptr)
        {
            return false;
        }
        if (!mContext->mBoard->removePiece(mPiece, mPt))
        {
            return false;
        }
        if (!mContext->mSet->removePiece(mPiece, mColor))
        {
            return false;
        }
        Piece* tmpPiece = mPiece;
        mPiece = nullptr;
        delete tmpPiece;
        return true;
    }
private:
    GridPoint mPt;
    bool mColor;
    Piece* mPiece;
};

#endif //CHESSENGINE_MAKEPIECE_H
