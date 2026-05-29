//
// Created by benja on 5/8/2026.
//

#ifndef CHESSENGINE_CONTEXT_H
#define CHESSENGINE_CONTEXT_H
//#include "../NewBoard.h"
#include "../Composite/PieceSet.h"

class Board;
class Context
{
public:
    Context(Board* board, PieceSet* set) : mBoard(board), mSet(set)
    {
    }
    ~Context()
    {
        delete mSet;
    }
    Board* mBoard;
    PieceSet* mSet;
};


#endif //CHESSENGINE_CONTEXT_H
