//
// Created by benja on 3/8/2026.
//

#include "pieces/King.h"


void King::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}

/*King::King(const Board& board, const bool color) : Piece(board, 0, color, 'K') {

}

std::list<GridPoint> King::getMoves(GridPoint& rhs) {
    int x = -1;
    int y = 1;

    for (int i = 0; i < 8; ++i) {
        if (i % 4 == 3) {
            if (getEligibility2(rhs.x() + x, rhs.y())) {
                mMoves.emplace_back(rhs.x() + x, rhs.y());
            }
            y *= -1;
        } else {
            if (getEligibility2(rhs.x() + x, rhs.y() + y)) {
                mMoves.emplace_back(rhs.x() + x, rhs.y() + y);
            }
        }
        if (i < 2) {
            ++x;
        } else if (x > 3 && x < 6) {
            --x;
        }
    }
    return mMoves;
}

Piece* King::clone() {
    const auto tmp = new King(*mBoard, getColor());
    return tmp;
}
*/