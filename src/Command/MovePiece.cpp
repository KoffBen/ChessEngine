//
// Created by benja on 5/28/2026.
//
#include "Command/MovePiece.h"

#include <sstream>

#include "CommandFactory.h"
#include "Board.h"
#include "Visitor/PrintVisitor.h"

bool MovePiece::execute()
{
    if (!checkValidMove()) return false;
    Piece* occPiece = mContext->mBoard->getPiece(endLoc);
    if (occPiece != nullptr)
    {
        std::stringstream ss;
        auto tmpVisitor = PrintVisitor(ss);
        occPiece->accept(tmpVisitor);
        auto newFactory = CommandFactory(mContext);
        makeOccPiece = newFactory.makeCommand(tolower(ss.str()[0]), endLoc, occPiece->getColor(), occPiece);
        if (!makeOccPiece->undo())
        {
            return false;
        }
    }
    if (!mContext->mBoard->movePiece(key, startLoc, endLoc, mPiece)) return false;
    mPiece->setPos(endLoc);
    return true;
}

bool MovePiece::undo()
{
    if (!mContext->mBoard->movePiece(key, endLoc, startLoc, mPiece)) return false;
    if (makeOccPiece != nullptr) makeOccPiece->execute();
    return true;
}

bool MovePiece::checkValidMove()
{
    if (!endLoc.isValid() || mPiece == nullptr) return false;
    Piece* tmp = mContext->mBoard->getPiece(endLoc);
    if (tmp != nullptr) if (tmp->getColor() == mPiece->getColor()) return false;
    return checkValidForPiece();
}

bool MovePiece::checkValidForPiece()
{
    std::stringstream ss;
    auto tmpVisitor = PrintVisitor(ss);
    mPiece->accept(tmpVisitor);
    
}
