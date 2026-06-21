//
// Created by Siyuan Cheng on 2022/4/24.
//

#include <cassert>
#include <iostream>
#include "less_than.h"
#include "matrix.h"
#include "stack.h"
#include "triangular.h"

using namespace std;

int main() {
    Triangular sequence(4);
    assert(sum(sequence) == 20); // 1 + 3 + 6 + 10

    Matrix matrix(2, 2);
    matrix.at(0, 1) = 3.5;
    Matrix matrix_copy = matrix;
    assert(matrix_copy.at(0, 1) == 3.5);

    Stack words;
    words.push("C++");
    std::string top;
    assert(words.peek(top) && top == "C++");

    int ia[16] = { 17, 12, 44, 9, 18, 45, 6, 14,
                   23, 67, 9, 0, 27, 55, 8, 16 };

    std::vector<int> vec( ia, ia+16 );
    int comp_val = 20;

    cout << "Number of elements less than "
         << comp_val << " are "
         << count_less_than( vec, comp_val ) << endl;

    print_less_than( vec, comp_val );
    cout << endl;

    return 0;
}
