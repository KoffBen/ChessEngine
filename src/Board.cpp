//
// Created by benja on 2/25/2026.
//

#include "Board.h"
#include "pieces/Rook.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Queen.h"
#include "pieces/King.h"
#include "pieces/Pawn.h"

void Board::resetPieces() {
    for (int i = 0; i < 32; ++i) {
        /*switch (i) {
            case 0:
            case 7:
                //I CAN'T DO THIS UNTIL I MAKE ALL THE PIECES FML
                //mPieces[i] = new Rook*
        }
        */
    }
}

void Board::resetBoard() {
    mColor = true;
    mEval = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i == 0 || i == 6) {

            }
        }
    }
}