//
// Created by benja on 5/31/2026.
//

#ifndef CHESSENGINE_GAME_H
#define CHESSENGINE_GAME_H
#include <iostream>
#include <stack>

#include "../Core/Board.h"

//The intention of this class is to encapsulate the rest of the code that has been written so far so that the user can interact much more smoothly with the structure.

class Game
{
public:
    /**
     * Constructor for a game, and setting up the board default
     * @param os The stream to which we will print
     */
    explicit Game(std::ostream& os) : colorTurn(true), mBoard(new Board()), lastBoard(), os(os), mFactory(mBoard->getContext())
    {
        mContext = mBoard->getContext();
        if (!setUpGame()) exit(1);
    }

    /**
     * This function creates a new setup for the board. We're storing the last board in case you want to quickly revert to it
     * @param placement The FEN string to tell the board how to set up
     * @return True if it's successful, false otherwise
     */
    bool ResetBoard(const std::string& placement);

    bool makeMove(std::string& move);

private:
    bool colorTurn;
    Board* mBoard;
    Board* lastBoard;
    Context* mContext;
    std::ostream& os;
    std::stack<Command*> mCommands;
    CommandFactory mFactory;

    [[nodiscard]] bool setUpGame() const;
    [[nodiscard]] bool isInCheck() const;
};

#endif //CHESSENGINE_GAME_H
