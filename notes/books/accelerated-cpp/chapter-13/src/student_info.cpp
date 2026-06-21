#include "student_info.h"

std::istream& Student_info::read(std::istream& is)
{
    char ch;
    if (!(is >> ch)) {
        return is;
    }

    Core* replacement = 0;
    if(ch == 'U') {
        replacement = new Core(is);
    } else {
        replacement = new Grad(is);
    }

    delete cp;
    cp = replacement;

    return is;
}
