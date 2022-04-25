//
// Created by Siyuan Cheng on 2022/4/24.
//

#include <iostream>
#include "less_than.h"

using namespace std;

int main() {
//    Triangular tri(4);
//    cout << tri.length() << "-- sum of elements: " << sum(tri) << endl;
//
//    Triangular tri2(4,3);
//    cout << tri.length() << "-- sum of elements: " << sum(tri) << endl;
//
//    Triangular tri3(4, 8);
//    cout << tri.length() << "-- sum of elements: " << sum(tri) << endl;

    int ia[16] = { 17, 12, 44, 9, 18, 45, 6, 14,
                   23, 67, 9, 0, 27, 55, 8, 16 };

    std::vector<int> vec( ia, ia+16 );
    int comp_val = 20;

    cout << "Number of elements less than "
         << comp_val << " are "
         << count_less_than( vec, comp_val ) << endl;

    print_less_than( vec, comp_val );

    return 0;
}
