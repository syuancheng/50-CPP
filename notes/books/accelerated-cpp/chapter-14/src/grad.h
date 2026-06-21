#ifndef SYUAN_GRAD_H
#define SYUAN_GRAD_H

#include "core.h"
#include <iostream>
#include <algorithm>

class Grad : public Core
{
private:
    double thesis;
public:
    Grad(/* args */):thesis(0){}
    Grad(std::istream& is){read(is);}

    //virtual function
    double grade() const;
    std::istream& read(std::istream&);

protected:
    Grad* clone() const { return new Grad(*this); }
};

#endif // SYUAN_GRAD_H