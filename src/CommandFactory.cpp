//
// Created by benja on 5/26/2026.
//
#include "CommandFactory.h"
#include "Command/MakePiece.h"
#include "Core/Context.h"

Command* CommandFactory::makeCommand(char pieceType, const GridPoint& pos, bool color)
{
    Command* mCommand;
    switch (pieceType)
    {
        case 'r':
            mCommand = new MakePiece<Rook>(mContext, pos, color);
            break;
        case 'n':
            mCommand = new MakePiece<Knight>(mContext, pos, color);
            break;
        case 'b':
            mCommand = new MakePiece<Bishop>(mContext, pos, color);
            break;
        case 'q':
            mCommand = new MakePiece<Queen>(mContext, pos, color);
            break;
        case 'k':
            mCommand = new MakePiece<King>(mContext, pos, color);
            break;
        case 'p':
            mCommand = new MakePiece<Pawn>(mContext, pos, color);
            break;
        default:
            mCommand = nullptr;
    }
    return mCommand;
}
