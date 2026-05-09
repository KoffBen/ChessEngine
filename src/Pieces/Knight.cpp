#include "pieces/Knight.h"

void Knight::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}