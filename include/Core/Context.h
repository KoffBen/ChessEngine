//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_CONTEXT_H
#define CHESSENGINE_CONTEXT_H
#include "../NewBoard.h"
#include "../Composite/PieceSet.h"

class Context
{
public:
    Context(NewBoard* board, PieceSet* set) : mBoard(board), mSet(set)
    {
    }
    ~Context()
    {
        delete mSet;
    }
    NewBoard* mBoard;
    PieceSet* mSet;
};


#endif //CHESSENGINE_CONTEXT_H
