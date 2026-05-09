//
// Created by benja on 5/8/2026.
//

#include "pieces/Pawn.h"

void Pawn::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}
