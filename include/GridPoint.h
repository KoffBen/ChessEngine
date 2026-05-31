//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_NEWGRIDPOINT_H
#define CHESSENGINE_NEWGRIDPOINT_H
//I honestly don't really care about abstraction or safety here.

class GridPoint
{
public:
    GridPoint() : x(0), y(0)
    {

    }
    GridPoint(int x, int y) : x(x), y(y)
    {

    }

    GridPoint(const GridPoint& rhs)
    {
        *this = rhs;
    }

    GridPoint& operator=(const GridPoint& rhs)
    {
        if (this == &rhs) return *this;

        x = rhs.x;
        y = rhs.y;

        return *this;
    }

    bool operator==(const GridPoint& rhs) const
    {
        return (x == rhs.x) && (y == rhs.y);
    }

    bool operator!=(const GridPoint& rhs) const
    {
        return !(*this == rhs);
    }


    GridPoint operator+(const GridPoint& rhs) const
    {
        GridPoint newGP = *this;

        newGP.x += rhs.x;
        newGP.y += rhs.y;

        return newGP;
    }

    GridPoint& operator+=(const GridPoint& rhs)
    {
        *this = *this + rhs;
        return *this;
    }

    [[nodiscard]] bool isValid() const
    {
        return (x >= 0 && x < 8 && y >= 0 && y < 8);
    }

    int x;
    int y;
};
#endif //CHESSENGINE_NEWGRIDPOINT_H
