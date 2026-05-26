//
// Created by benja on 5/26/2026.
//

#include "pieces/Rook.h"

void Rook::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}