#include <iostream>

using namespace std;

struct User
{
    string name;
    int age;
    struct Sex
    {
        bool gender;
    };
    Sex sex;
    float* height;
};


int main() {
    float h = 1.85;

    float y = 1.95;

    User u;
    u.name = "moss";
    u.age = 58;
    u.sex.gender = false;
    u.height = &h;
    cout << "u  pointer:" << &u << ", target: " << u.name << ", height: " << *u.height << " at " << u.height << endl;

    cout << "=========" << endl;

    User u1 = u;
    u1.name = "550w";
    u1.height = &y;
    cout << "u1 pointer:" << &u1 << ", target: " << u1.name << ", height: " << *u1.height << " at " << u1.height << endl;
    cout << "u  pointer:" << &u << ", target: " << u.name << ", height: " << *u.height << " at " << u.height << endl;

    cout << "=========" << endl;

    User* u2 = &u;
    u2->name = "550c";
    u2->height = &y;
    cout << "u2 pointer:" << &u2 << ", target: " << u2->name << ", height: " << *u2->height << " at " << u2->height << endl;
    cout << "u  pointer:" << &u << ", target: " << u.name << ", height: " << *u.height << " at " << u.height << endl;

    cout << "=========" << endl;

    User& u3 = u;
    u3.name = "550a";
    u3.height = &y;
    cout << "u3 pointer:" << &u3 << ", target: " << u3.name << ", height: " << *u3.height << " at " << u3.height << endl;
    cout << "u  pointer:" << &u << ", target: " << u.name << ", height: " << *u.height << " at " << u.height << endl;

    cout << "=========" << endl;

    return 0;
}
