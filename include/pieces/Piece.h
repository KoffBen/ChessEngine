//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_PIECE_H
#define CHESSENGINE_PIECE_H

#include "GridPoint.h"
#include "Visitor/Visitor.h"

class Board;

class Piece {

public:
    explicit Piece(const NewGridPoint pt, const bool color) : mColor(color), mPt(pt)
    {

    }

    virtual ~Piece() = default;

    virtual void accept(Visitor& visitor) const = 0;

    void setPos(const NewGridPoint pt)
    {
        mPt = pt;
    }

    [[nodiscard]] NewGridPoint getPos() const
    {
        return mPt;
    }

    bool getColor() const
    {
        return mColor;
    }

private:
    bool mColor;
    NewGridPoint mPt;
};

#endif //CHESSENGINE_PIECE_H