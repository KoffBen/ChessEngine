//
// Created by benja on 5/26/2026.
//

#include "Board.h"

#include "Command/MakePiece.h"

bool Board::defaultSetup()
{
    return givenSetup("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR", true);
}
//Hold off for now, until we figure out the right format from UCI
bool Board::givenSetup(std::string placement, bool standard)
{
    if (!standard) if (!checkValidSetup(placement)) return false;
    GridPoint pt(0, 7);
    for (char i : placement)
    {
        if (i > 48 && i < 57)
        {
            pt.x += i - 48;
        } else if (i == '/')
        {
            pt.x = 0;
            pt.y -= 1;
        } else
        {
            Command* tmp = nullptr;
            tmp = mFactory.makeCommand(tolower(i), pt, std::isupper(i));
            if (tmp == nullptr)
            {
                return false;
            }
            if (!tmp->execute())
            {
                return false;
            }
            pt.x += 1;
        }
    }
    return true;
}

bool Board::addPiece(Piece* piece)
{
    GridPoint pt = piece->getPos();
    if (mBoard[pt.x][pt.y] != nullptr)
    {
        return false;
    }
    mBoard[pt.x][pt.y] = piece;
    return true;
}

bool Board::removePiece(Piece* piece, GridPoint pt)
{
    if (mBoard[pt.x][pt.y] == nullptr || mBoard[pt.x][pt.y] != piece)
    {
        return false;
    }
    mBoard[pt.x][pt.y] = nullptr;
    return true;
}

Piece* Board::getPiece(GridPoint pt) const
{
    return mBoard[pt.x][pt.y];
}

bool Board::clear()
{
    delete mContext.mSet;
    mContext.mSet = new PieceSet();
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            mBoard[i][j] = nullptr;
        }
    }
    return true;
}

bool Board::checkValidSetup(const std::string& setup)
{
    int countDigits = 0;
    int countSections = 0;

    for (char i : setup)
    {
        i = tolower(i);
        if (i > 48 && i < 57)
        {
            countDigits += i - 48;
        } else if (i == 'r' || i == 'n' || i == 'b' || i == 'q' || i == 'k' || i == 'p')
        {
            countDigits += 1;
        } else if (i == '/')
        {
            if (countDigits != 8) return false;
            countDigits = 0;
            countSections += 1;
        } else
        {
            return false;
        }
        if (countDigits > 8) return false;
    }
    return countSections == 7 && countDigits == 8;
}

void Board::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}

bool Board::movePiece([[maybe_unused]]PassKey& key, const GridPoint& prevLoc, const GridPoint& newLoc, Piece* movingPiece)
{
    if (getPiece(newLoc) != nullptr || getPiece(prevLoc) != movingPiece) return false;
    mBoard[prevLoc.x][prevLoc.y] = nullptr;
    mBoard[newLoc.x][newLoc.y] = movingPiece;
    return true;
}
