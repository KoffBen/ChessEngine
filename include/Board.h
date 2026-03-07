//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_BOARD_H
#define CHESSENGINE_BOARD_H

#include <string>
#include "Square.h"


class Board {
public:
    //Default Constructor
    Board() : mSquares(), mColor(true), mEval(0) {
        resetBoard();
    }
    //Copy Constructor
    Board(const Board& rhs) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                mSquares[i][j] = rhs.mSquares[i][j];
            }
        }

        for (int i = 0; i < 32; ++i) {
            mPieces[i] = rhs.mPieces[i];
        }
    }
    //Copy Operator
    Board& operator=(const Board& rhs);
    //Destructor
    ~Board();

    /**
     * Returns true if the GridPoint is on the board, false otherwise
     */
    bool isOnBoard(const GridPoint& rhs) const;

    /**
     * Returns true if the GridPoint is on the board, false otherwise
     */
    bool isOnBoard(int x, int y) const;

    /**
     * Determines if a GridPoint is eligible
     */
    bool isEligiable(const GridPoint& rhs) const;

    /**
     * Returns the color that the board's perspective is in
     */
    bool getColor() const;

    /**
     * Changes the color of the board
     */
    void setColor(bool rhs);

    /**
     * Gets the evaluation of the current board
     */
    int getEval();

    /**
     * Evaluates the eval at the current board
     */
    void calcEval();

    /**
     * Get a string representation of the board
     */
    std::string toString();


private:
    /**
     * The squares that make up the board
     */
    Square mSquares[8][8];

    /**
     * All of the pieces that may come up in the game
     */
    Piece* mPieces[32];

    /**
     * Is this board from white's perspective
     */
    bool mColor;

    /**
     * The evaluation of the present state of the board
     */
    double mEval;

    void resetPieces();

    void resetBoard();
};

#endif //CHESSENGINE_BOARD_H