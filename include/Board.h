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
    Board();
    //Copy Constructor
    Board(const Board& rhs);
    //Copy Operator
    Board& operator=(const Board& rhs) = delete;
    //Destructor
    ~Board();

    /**
     * Returns true if the GridPoint is on the board, false otherwise
     */
    [[nodiscard]] bool isOnBoard(const GridPoint& rhs) const;

    /**
     * Returns true if the GridPoint is on the board, false otherwise
     */
    [[nodiscard]] bool isOnBoard(int x, int y) const;

    /**
     * Determines if a GridPoint is eligible
     * Eligibility is defined as being on the board, and having the associated square not be
     * occupied by a piece of the same color as the board
     */
    [[nodiscard]] bool isEligible(const GridPoint& rhs) const;

    /**
     * Returns the color that the board's perspective is in
     */
    [[nodiscard]] bool getColor() const;

    /**
     * Changes the color of the board
     */
    void setColor(bool rhs);

    /**
     * Gets the evaluation of the current board
     */
    double getEval();

    /**
     * Get a string representation of the board
     */
    std::string toString();

    const Square& getSquare(const GridPoint& rhs) const;


private:
    /**
     * The squares that make up the board
     */
    Square mSquares[8][8];

    /**
     * All of the pieces that may come up in the game
     */
    Piece** mPieces;

    /**
     * Is this board from white's perspective
     */
    bool mColor;

    /**
     * The evaluation of the present state of the board
     */
    double mEval;

    /**
     * Evaluates the eval at the current board
     */
    void calcEval();

    /**
     * Resets the array mPieces to exist at it's initial state, holding all the necessary pieces
     * of the board
     */
    void resetPieces();

    /**
     * Resets the board to its initial state, resetting the pieces and putting them in their
     * starting states
     */
    void resetBoard();
};

#endif //CHESSENGINE_BOARD_H