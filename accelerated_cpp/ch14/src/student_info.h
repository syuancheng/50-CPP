#ifndef SYUAN_STUDENT_INFO_H
#define SYUAN_STUDENT_INFO_H

#include <iostream>
#include <string>
#include "core.h"
#include "grad.h"
#include "handle.h"

class Student_info
{
public:
    Student_info(){}
    Student_info(std::istream& is){ read(is); }
    //操作
    std::istream& read(std::istream&);

    std::string name() const {
        if (cp)
        {
            return cp->name();
        } else {
            throw std::runtime_error("uninitialized student");
        }
    }

    double grade() const {
        if (cp)
        {
            return cp->grade();
        }else {
            throw std::runtime_error("uninitialized student");
        }
    }

    static bool compare(const Student_info& s1, const Student_info& s2) {
        return s1.name() < s2.name();
    } 
private:
    Handle<Core> cp;
};

#endif // SYUAN_STUDENT_INFO_H