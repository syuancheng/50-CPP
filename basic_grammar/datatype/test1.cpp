#include <iostream>

using namespace std;

int main()
{
    unsigned u = 10, u2 = 42;
    cout << u2 - u << endl; // 32
    cout << u - u2 << endl; // 4294967264, 当i=0的时候， --i不会变为-1， 而是4294967264。对于无符号的数字，必须确保运算侯的值也是无符号的。
    cout << u * u2 << endl; // 420

    // for (unsigned i = 10; i >= 0; --i)
    // {
    //     // 当i=0的时候， --i不会变为-1， 而是4294967264。对于无符号的数字，必须确保运算侯的值也是无符号的。
    //     cout << i << endl;
    // }

    return 0;
}