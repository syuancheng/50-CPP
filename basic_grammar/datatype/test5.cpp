#include <iostream>

using namespace std;

struct Student
{
    string name;
    int age;
    float* height;
};

void test1(const Student& student) {
    cout << "student pointer:" << &student << ", target: " << student.name << endl;
    Student newStu;
    cout << "newStu1 pointer:" << &newStu << ", target: " << newStu.name << endl;
    newStu = student;
    cout << "newStu2 pointer:" << &newStu << ", target: " << newStu.name << endl;

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
