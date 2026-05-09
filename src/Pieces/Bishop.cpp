//
// Created by benja on 2/25/2026.
//



//Bishop::Bishop(const Board& board, const bool color) : Piece(board, 3, color, 'B') {

#include "pieces/Bishop.h"
//}
void Bishop::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}

/*
std::list<GridPoint> Bishop::getMoves(GridPoint& rhs) {
    bool ignore[] = {false, false, false, false};
    int xSign = 1, ySign = 1;

    for (int i = 1; i < 8; ++i) {
        for (int j = 0; j < 4; ++j) {
            const int eligibility = getEligibility(rhs.x() + i * xSign, rhs.y() + i * ySign);
            if (!ignore[j]) {
                if (eligibility == 0) {
                    ignore[j] = true;
                } else {
                    if (eligibility == 1) {
                        ignore[j] = true;
                    }
                    mMoves.emplace_back(rhs.x() + i * xSign, rhs.y() + i * ySign);
                }
            }
            if (j % 2 == 0) {ySign *= -1;} else {xSign *= -1;}
        }
    }
    return mMoves;
}
*/
