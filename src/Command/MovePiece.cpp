//
// Created by benja on 5/28/2026.
//
#include "Command/MovePiece.h"

#include <sstream>

#include "../../include/FactoryInterpreter/CommandFactory.h"
#include "../../include/Core/Board.h"
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
    mPiece->setPos(startLoc);
    return true;
}

bool MovePiece::checkValidMove() const
{
    if (!endLoc.isValid() || mPiece == nullptr) return false;
    Piece* tmp = mContext->mBoard->getPiece(endLoc);
    if (tmp != nullptr) if (tmp->getColor() == mPiece->getColor()) return false;
    return checkValidForPiece();
}

bool MovePiece::checkValidForPiece() const
{
    std::stringstream ss;
    auto tmpVisitor = PrintVisitor(ss);
    mPiece->accept(tmpVisitor);
    const char switchChar = tolower(ss.str()[0]);

    if (endLoc == startLoc) return false;

    switch (switchChar)
    {
    case 'r':
        return checkRook();
    case 'n':
        return (startLoc.x != endLoc.x) && (startLoc.y != endLoc.y) && ((std::abs(startLoc.x - endLoc.x) + std::abs(startLoc.y - endLoc.y)) == 3);
    case 'b':
        return checkBishop();
    case 'q':
        return checkRook() || checkBishop();
    case 'k':
        return (std::abs(startLoc.x - endLoc.x) <= 1) && (std::abs(startLoc.y - endLoc.y) <= 1);
    case 'p':
        return checkPawn();
    default:
        return false;
    }

}

bool MovePiece::checkRook() const
{
    if (endLoc.x != startLoc.x && endLoc.y != startLoc.y) return false;

    GridPoint tmp;

    int dy = endLoc.y - startLoc.y;
    int dx = endLoc.x - startLoc.x;

    auto adder = GridPoint(dx != 0 ? (dx / std::abs(dx)) : 0, dy != 0 ? (dy / std::abs(dy)) : 0);

    return checkHelper(adder);

    // if (endLoc.x != startLoc.x)
    // {
    //     if (endLoc.x > startLoc.x)
    //     {
    //         for (tmp = startLoc + GridPoint(1, 0); tmp.x < endLoc.x; ++tmp.x)
    //         {
    //             if (mContext->mBoard->getPiece(tmp) != nullptr) return false;
    //         }
    //     } else
    //     {
    //         for (tmp = startLoc + GridPoint(-1, 0); tmp.x > endLoc.x; --tmp.x)
    //         {
    //             if (mContext->mBoard->getPiece(tmp) != nullptr) return false;
    //         }
    //     }
    // } else
    // {
    //     if (endLoc.y > startLoc.y)
    //     {
    //         for (tmp = startLoc + GridPoint(0, 1); tmp.y < endLoc.y; ++tmp.y)
    //         {
    //             if (mContext->mBoard->getPiece(tmp) != nullptr) return false;
    //         }
    //     } else
    //     {
    //         for (tmp = startLoc + GridPoint(0, -1); tmp.y > endLoc.y; --tmp.y)
    //         {
    //             if (mContext->mBoard->getPiece(tmp) != nullptr) return false;
    //         }
    //     }
    // }
    //
    // return true;
}

bool MovePiece::checkBishop() const
{
    int dy, dx;
    if (std::abs(dy = endLoc.y - startLoc.y) != std::abs(dx = endLoc.x - startLoc.x)) return false;
    auto adder = GridPoint(dx / std::abs(dx), dy / std::abs(dy));
    return checkHelper(adder);
}

bool MovePiece::checkHelper(const GridPoint& adder) const
{
    for (GridPoint tmp = startLoc + adder; tmp != endLoc; tmp += adder)
    {
        if (mContext->mBoard->getPiece(tmp) != nullptr) return false;
    }
    return true;
}

bool MovePiece::checkPawn() const
{
    if (startLoc.x != endLoc.x) return false;
    if (startLoc.y == 1 || startLoc.y == 6)
    {
        return (std::abs(startLoc.y - endLoc.y) <= 2);
    }
    return std::abs(startLoc.y - endLoc.y) < 2;
}