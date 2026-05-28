//
// Created by benja on 5/17/2026.
//

#include "../../include/Command/DefaultBoard.h"
#include "Board.h"

bool DefaultBoard::execute()
{
    return mContext->mBoard->defaultSetup();
}

bool DefaultBoard::undo()
{
    return mContext->mBoard->clear();
}
