//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_PIECE_H
#define CHESSENGINE_PIECE_H

#include "../Core/GridPoint.h"
#include "Visitor/Visitor.h"

class Piece {

public:
    explicit Piece(const GridPoint pt, const bool color) : mColor(color), mPt(pt)
    {

    }

    virtual ~Piece() = default;

    virtual void accept(Visitor& visitor) const = 0;

    void setPos(const GridPoint pt)
    {
        mPt = pt;
    }

    [[nodiscard]] GridPoint getPos() const
    {
        return mPt;
    }

    bool getColor() const
    {
        return mColor;
    }

private:
    bool mColor;
    GridPoint mPt;
};

#endif //CHESSENGINE_PIECE_H