//
// Created by benja on 5/26/2026.
//
#include "../../include/FactoryInterpreter/CommandFactory.h"
#include "Command/MakePiece.h"
#include "Command/MovePiece.h"
#include "Core/Context.h"
#include "pieces/Piece.h"

Command* CommandFactory::makeCommand(char pieceType, const GridPoint& pos, bool color)
{
    return makeCommand(pieceType, pos, color, nullptr);
}

Command* CommandFactory::makeCommand(char pieceType, const GridPoint& pos, bool color, Piece* piece)
{
    Command* mCommand;
    switch (pieceType)
    {
    case 'r':
        mCommand = new MakePiece<Rook>(mContext, pos, color, piece);
        break;
    case 'n':
        mCommand = new MakePiece<Knight>(mContext, pos, color, piece);
        break;
    case 'b':
        mCommand = new MakePiece<Bishop>(mContext, pos, color, piece);
        break;
    case 'q':
        mCommand = new MakePiece<Queen>(mContext, pos, color, piece);
        break;
    case 'k':
        mCommand = new MakePiece<King>(mContext, pos, color, piece);
        break;
    case 'p':
        mCommand = new MakePiece<Pawn>(mContext, pos, color, piece);
        break;
    default:
        mCommand = nullptr;
    }
    return mCommand;
}

Command* CommandFactory::makeMoveCommand(const std::string& move)
{
    if (!checkMoveString(move)) return nullptr;

    auto firstLoc = GridPoint((move[0] - 'a'), move[1] - '1');
    auto secondLoc = GridPoint(move[2] - 'a', move[3] - '1');

    Piece* movingPiece = mContext->mBoard->getPiece(firstLoc);
    if (movingPiece == nullptr) return nullptr;

    Command* movePiece = new MovePiece(mContext, movingPiece, secondLoc);

    return movePiece;
}

bool CommandFactory::checkMoveString(const std::string& checkString) const
{
    int length = checkString.length();
    if ((length != 4) && length != 5) return false;
    if (checkString[0] > 'h' || checkString[0] < 'a' || checkString[2] > 'h' || checkString[2] < 'a') return false;
    if (checkString[1] > '8' || checkString[1] < '1' || checkString[3] > '8' || checkString[3] < '1') return false;
    if (length == 5)
    {
        if (checkString[4] == 'q' || checkString[4] == 'r' || checkString[4] == 'b' || checkString[4] == 'n') return true;
        return false;
    }
    return true;
}
