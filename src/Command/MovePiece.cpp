//
// Created by benja on 5/28/2026.
//
#include "Command/MovePiece.h"

#include "Board.h"

bool MovePiece::execute()
{
    if (!checkValidMove()) return false;
    Piece* tmp = mContext->mBoard->getPiece(endLoc);
    if (tmp == nullptr) mContext->mBoard
    return true;
}

bool MovePiece::undo()
{
    return true;
}

bool MovePiece::checkValidMove()
{
    if (!endLoc.isValid() || mPiece == nullptr) return false;
    Piece* tmp = mContext->mBoard->getPiece(endLoc);
    if (tmp != nullptr) if (tmp->getColor() == mPiece->getColor()) return false;
    return true;
}
