//
// Created by benja on 5/17/2026.
//
#include "Command/MakeRook.h"

#include "pieces/Rook.h"

bool MakeRook::execute()
{
    auto* mRook = new Rook(mPt);
    mContext->mBoard->addPiece(mRook);
    mContext->mSet->addPiece(mRook, mColor);
    return true;
}