//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_NEWGRIDPOINT_H
#define CHESSENGINE_NEWGRIDPOINT_H
//I honestly don't really care about abstraction or safety here.

class NewGridPoint
{
public:
    NewGridPoint() : x(0), y(0)
    {

    }
    NewGridPoint(int x, int y) : x(x), y(y)
    {

    }

    bool isValid() const
    {
        return (x >= 0 && x < 8 && y >= 0 && y < 8);
    }

    int x;
    int y;
};
#endif //CHESSENGINE_NEWGRIDPOINT_H
