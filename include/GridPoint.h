//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_GRIDPOINT_H
#define CHESSENGINE_GRIDPOINT_H

class GridPoint {
public:
    //Default Constructor
    GridPoint(const int& x, const int& y) : mx(x), my(y) {

    }

    //Destructor
    ~GridPoint() = default;

    //Copy Constructor
    GridPoint(const GridPoint& rhs);

    //Copy Operator
    GridPoint& operator=(const GridPoint& rhs) = default;

    //Alternate Constructor
    GridPoint(const char& x, const int& y) : mx(x - 'A'), my(y) {

    }

    /**
     * gets the x coordinate
     * @return x value position
     */
    int x() const;

    /**
     * sets mx with the character location
     * @param xChar the character corresponding to the grid
     */
    void x(const char& xChar);

    /**
     * sets mx with its location on the grid
     * @param xInt the integer corresponding to the x location on the grid
     */
    void x(const int& xInt);

    /**
     * gets the y value for the position vector
     * @return y value position
     */
    int y() const;

    /**
     * sets my with the value for the y position
     * @param yInt the new value for the y position
     */
    void y(const int& yInt);

private:
    int mx;
    int my;
};

#endif //CHESSENGINE_GRIDPOINT_H