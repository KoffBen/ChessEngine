//
// Created by benja on 5/26/2026.
//

#include "NewBoard.h"

#include "Command/MakePiece.h"

void NewBoard::defaultSetup()
{

}
//Hold off for now, until we figure out the right format from UCI
bool NewBoard::givenSetup(std::string& placement)
{
    bool success = true;
    NewGridPoint pt(0, 7);
    for (char i : placement)
    {
        if (i > 48 && i < 57)
        {
            pt.x += i - 48;
        } else
        {
            Command* tmp;
            tmp = mFactory.makeCommand(i, pt, std::isupper(i));
            if (tmp == nullptr)
            {
                return false;
            }
            if (!tmp->execute())
            {
                success = false;
            }
        }
    }
    return success;
}

bool NewBoard::addPiece(Piece* piece)
{
    NewGridPoint pt = piece->getPos();
    if (mBoard[pt.x][pt.y] != nullptr)
    {
        return false;
    }
    mBoard[pt.x][pt.y] = piece;
    return true;
}

bool NewBoard::removePiece(Piece* piece, NewGridPoint pt)
{
    if (mBoard[pt.x][pt.y] == nullptr || mBoard[pt.x][pt.y] != piece)
    {
        return false;
    }
    mBoard[pt.x][pt.y] = nullptr;
    return true;
}

Piece* NewBoard::getPiece(NewGridPoint pt)
{
    return mBoard[pt.x][pt.y];
}
