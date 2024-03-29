#include "student_info.h"
#include "grade.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
    is >> s.name >> s.midterm >> s.final;
    
    read_hw(is, s.homework);
    return is;
}

istream& read_hw(istream& is, vector<double>& hw) {
    if (is)
    {
        hw.clear();

        double x;
        while (is >> x)
        {
            hw.push_back(x);
        }
        is.clear();
    }
    return is;
}

std::vector<Student_info> extract_fails(std::vector<Student_info>& students) {
    std::vector<Student_info> fail;
    std::vector<Student_info>::iterator iter = students.begin();

    while (iter != students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else {
            ++iter;
        }
        
    }
    return fail;
}

std::list<Student_info> extract_fails(std::list<Student_info>& students) {
    std::list<Student_info> fail;
    std::list<Student_info>::iterator iter = students.begin();

    while (iter != students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else {
            ++iter;
        }
        
    }
    return fail;
}