#include <iostream>

using namespace std;

int main() {
    int n = 3;

    switch (n)
    {
    case 1:
        cout << "This is 1" << endl;
        break;
    case 2:
        cout << "This is 2" << endl;
        break;
    case 3:
        cout << "This is 3" << endl;
        break;
    default:
        cout << "This is default" << endl;
        break;
    }


    return 0;
}