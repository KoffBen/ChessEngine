//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_NEWBOARD_H
#define CHESSENGINE_NEWBOARD_H

#include <string>

#include "Core/Context.h"
#include "CommandFactory.h"
#include "pieces/Piece.h"

class Piece;

//Called NewBoard for the time being because it's replacing Board, but I want to leave that code intact for smooth transition
class NewBoard
{
public:
    NewBoard() : mContext(this, new PieceSet()), mFactory(&mContext), eval(0)
    {

    }

    //Deep Delete -- wait we're deep deleting these twice. Hmm. Okay we'll delete from the composite when we kill the interface
    ~NewBoard() = default;

    bool defaultSetup();

    //IMPORTANT: This is to be adapted with UCI Specs
    bool givenSetup(std::string placement, bool standard);

    bool addPiece(Piece* piece);

    bool removePiece(Piece* piece, NewGridPoint pt);

    [[nodiscard]] Piece* getPiece(NewGridPoint pt) const;

    bool clear();

    void accept(Visitor& visitor) const;
private:
    Context mContext;

    Piece* mBoard[8][8] = {};

    CommandFactory mFactory;

    double eval;

    static bool checkValidSetup(const std::string& setup);
};

#endif //CHESSENGINE_NEWBOARD_H
