//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_PIECE_H
#define CHESSENGINE_PIECE_H

#include <list>
#include <stdexcept>

#include "NewGridPoint.h"
#include "../GridPoint.h"
#include "Visitor/Visitor.h"

class Board;

class Piece {

public:
    explicit Piece(const NewGridPoint pt) : mPt(pt)
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

    bool setSetLoc(const int sl)
    {
        if (setLoc == -1)
        {
            setLoc = sl;
            return true;
        }
        return false;
    }

    [[nodiscard]] int getSetLoc() const
    {
        if (setLoc == -1)
        {
            throw std::runtime_error("Trying to access an unset variable");
        }
        return setLoc;
    }
private:
    NewGridPoint mPt;
    int setLoc = -1;
};

#endif //CHESSENGINE_PIECE_H