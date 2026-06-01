//
// Created by benja on 5/31/2026.
//
#include "Facade/Game.h"

#include "Command/Command.h"

bool Game::ResetBoard(const std::string& placement)
{
    auto newBoard = new Board();
    if (!newBoard->givenSetup(placement, false))
    {
        os << "ERROR: Failed to reset the board \n";
        return false;
    }
    delete lastBoard;
    lastBoard = mBoard;
    mBoard = newBoard;
    mContext = newBoard->getContext();
    auto tmpFactory = CommandFactory(mContext);
    std::swap(mFactory, tmpFactory);
    return true;
}

bool Game::makeMove(std::string& move)
{
    if (isInCheck())
    {
        os << "ERROR: Attempting to move while in check";
        return false;
    }
    Command* movePiece = mFactory.makeMoveCommand(move);
    if (movePiece == nullptr)
    {
        os << "ERROR: No piece at the designated location\n";
        return false;
    }

    auto firstLoc = GridPoint((move[0] - 'a'), move[1] - '1');
    if (mBoard->getPiece(firstLoc)->getColor() != colorTurn)
    {
        os << "ERROR: Attempting to move out of turn\n";
        return false;
    }

    if (!movePiece->execute())
    {
        os << "ERROR: Piece failed to move\n";
        return false;
    }
    mCommands.push(movePiece);
    colorTurn = !colorTurn;
    return true;
}

bool Game::setUpGame() const
{
    if (!mBoard->defaultSetup())
    {
        os << "ERROR: Failed to setup the game. \n";
        return false;
    }
    os << "Board is setup! \n";
    return true;
}