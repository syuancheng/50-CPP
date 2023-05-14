#ifndef SYUAN_STUDENT_INFO_H
#define SYUAN_STUDENT_INFO_H

#include <iostream>
#include <string>
#include "core.h"
#include "grad.h"

class Student_info
{
public:
    Student_info():cp(0){}
    Student_info(std::istream& is):cp(0){ read(is); }
    Student_info(const Student_info& s):cp(0)
    {
        if(s.cp) {
            cp=s.cp->clone();
        }
    };
    
    Student_info& operator=(const Student_info& s)
    {
        if (&s != this)
        {
            delete cp;
            if (s.cp)
            {
                cp = s.cp->clone();
            } else {
                cp = 0;
            }
            
        }
        return *this;
    };

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
    
    ~Student_info(){ delete cp; }
    
private:
    Core* cp;
};



#endif // SYUAN_STUDENT_INFO_H