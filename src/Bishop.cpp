//
// Created by benja on 2/25/2026.
//

#include "pieces/Bishop.h"

void Bishop::findMoves() {
    bool ignore[] = {false, false, false, false};
    int xSign = 1, ySign = 1;

    for (int i = 1; i < 8; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!ignore[j]) {
                if (auto newCoord = GridPoint(mLoc.x() + i*xSign, mLoc.y() + i*ySign); !mBoard.isEligiable(newCoord)) {
                    ignore[j] = true;
                } else {
                    if (mBoard.getSquare(newCoord).isOccupied() && (mBoard.getSquare(newCoord)
                        .getColor()
                    == mBoard.getColor())) {
                        ignore[j] = true;
                    }
                    mMoves.push(newCoord);
                }
            }
            if (j % 2 == 0) {ySign *= -1;} else {xSign *= -1;}
        }
    }
}
