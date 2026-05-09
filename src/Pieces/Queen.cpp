//
// Created by benja on 5/8/2026.
//

#include "pieces/Queen.h"

void Queen::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}
