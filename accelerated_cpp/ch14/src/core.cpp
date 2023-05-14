#include "core.h"

std::string Core::name() const
{
    return n;
}

std::istream& Core::read_common(std::istream& in)
{
    in>>n>>midterm>>final;
    return in;
}

std::istream& Core::read(std::istream& in)
{
    read_common(in);
    read_hw(in, homework);
    return in;
}

std::istream& read_hw(std::istream& is, std::vector<double>& hw) {
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

double Core::grade() const
{
    return ::grade(midterm, final, homework);
}

double grade(double midterm, double final, const std::vector<double>& hw) {
    if (hw.size() == 0)
    {
        throw std::domain_error("student has done no homework");
    }
    return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double hw) {
    
    return midterm * 0.2 + hw * 0.2 + final * 0.6;
} 

double median(std::vector<double> vec) {
    typedef std::vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size == 0)
    {
        throw std::domain_error("median of an empty vector");
    }
    std::sort(vec.begin(), vec.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (vec[mid]+vec[mid-1]) / 2 : vec[mid];
}

bool compare_core_ptrs(const Core* cp1, const Core* cp2)
{
    return compare(*cp1, *cp2);
}

//name is a func in basic class
bool compare(const Core& c1, const Core& c2)
{
    return c1.name() < c2.name();
}

//grade virtual
bool compare_grades(const Core& c1, const Core& c2)
{
    return c1.grade() < c2.grade();
}

bool compare_grades_static(Core c1, Core c2)
{
    return c1.grade() < c2.grade();
}