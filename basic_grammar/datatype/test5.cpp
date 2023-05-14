#include <iostream>

using namespace std;

struct Student
{
    string name;
    int age;
    float* height;
};

void test1(Student& student) {
    cout << "student pointer:" << &student << ", target: " << student.name << endl;

    Student& newStu = student;
    cout << "newStu  pointer:" << &newStu << ", target: " << newStu.name << endl;

    Student copyStu = student;    
    cout << "copyStu pointer:" << &copyStu << ", target: " << copyStu.name << endl;


}

int main() {
    Student s;
    s.name = "krystal";
    s.age = 18;

    cout << "s       pointer:" << &s << ", target: " << s.name << endl;

    test1(s);

    cout << "=========" << endl;

    return 0;
}
