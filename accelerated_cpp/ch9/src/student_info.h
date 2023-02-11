#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H

#include <string>
#include <vector>
#include <iostream>

class Student_info
{
private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
public:
    Student_info(): midterm(0), final(0) {}//缺省构造
    Student_info(std::istream&);

    double grade() const;

    std::istream& read(std::istream&);
    std::istream& read_hw(std::istream&, std::vector<double>&);
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }
};

double grade(double, double, const std::vector<double>&);
double grade(double, double, double);
double median(std::vector<double>);
bool compare(const Student_info&, const Student_info&);


#endif