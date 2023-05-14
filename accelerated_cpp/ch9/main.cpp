#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "src/student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main() {
    vector<Student_info> students;

    Student_info record;
    string::size_type maxlen = 0;

    while (record.read(cin))
    {
        maxlen = std::max(maxlen, record.name().size());
        students.push_back(record);
    }
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
    {
        cout << std::setw(maxlen + 1) << students[i].name(); 
        try
        {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec) << endl;
        }
        catch(domain_error e)
        {
            cout << e.what() << endl;
        }
        
    }
    return 0;
}