#include "student_info.h"

Student_info::Student_info(std::istream& is)
{
    read(is);
}



double grade(double midterm, double final, const std::vector<double>& hw) {
    if (hw.size() == 0)
    {
        throw std::domain_error("student has done no homework");
    }
    return grade(midterm, final, median(hw));
}

double Student_info::grade() const {
    return grade(midterm, final, homework);
}

double Student_info::grade(double midterm, double final, double hw) {
    
    return midterm * 0.2 + hw * 0.2 + final * 0.6;
} 

double Student_info::median(std::vector<double> vec) {
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

std::istream& Student_info::read(std::istream& in) {
    in >> n >> midterm >> final;
    read_hw(in, homework);
    return in;
}

std::istream& Student_info::read_hw(std::istream& is, std::vector<double>& hw) {
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

bool compare(const Student_info& lhs, const Student_info& rhs) {
    return lhs.name() < rhs.name();
}