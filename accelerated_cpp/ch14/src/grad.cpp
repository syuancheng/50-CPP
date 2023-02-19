#include "grad.h"

double Grad::grade() const
{
    return std::min(Core::grade(), thesis);
}

std::istream& Grad::read(std::istream& in)
{
    Core::read_common(in);
    in>>thesis;
    read_hw(in, Core::homework);
    return in;
}