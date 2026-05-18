//
// Created by benja on 5/18/2026.
//

#include "Command/MakeBishop.h"

#include "pieces/Bishop.h"

bool MakeBishop::execute()
{
    auto* mBishop = new Bishop(mPt);
    mContext->mBoard->addPiece(mBishop);
    mContext->mSet->addPiece(mBishop, mColor);
    return true;
}