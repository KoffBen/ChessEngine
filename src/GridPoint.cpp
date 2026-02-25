//
// Created by benja on 2/25/2026.
//

#include "GridPoint.h"

GridPoint::GridPoint(const GridPoint &rhs) {
    mx = rhs.mx;
    my = rhs.my;
}

int GridPoint::x() const {
    return mx;
}

void GridPoint::x(const char& xChar) {
    mx = xChar - 'a';
}

void GridPoint::x(const int& xInt) {
    mx = xInt;
}

int GridPoint::y() const {
    return my;
}

void GridPoint::y(const int& yInt) {
    my = yInt;
}