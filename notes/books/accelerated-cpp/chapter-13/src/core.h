#ifndef SYUAN_CORE_H
#define SYUAN_CORE_H

#include <iostream>
#include <string>
#include <vector>

class Core
{
public:
    friend class Student_info;

    Core():midterm(0),final(0){}
    Core(std::istream& is) {read(is);}

    std::string name() const;

    virtual std::istream& read(std::istream&);
    virtual double grade() const;
    //compare_grades函数执行时，将由参数的实际类型来决定调用基类or派生类的grade函数。
    virtual ~Core() {}

protected:
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;

    virtual Core* clone() const { return new Core(*this); }

private:
    std::string n;
};

std::istream& read_hw(std::istream&, std::vector<double>&);

double grade(double, double, const std::vector<double>&);

double grade(double, double, double);

double median(std::vector<double>);

bool compare(const Core&, const Core&);

bool compare_core_ptrs(const Core*, const Core*);

//动态绑定：运行的时候决定调用什么函数
bool compare_grades(const Core&, const Core&);

//静态绑定：编译的时候
bool compare_grades_static(Core, Core);

#endif // SYUAN_CORE_H