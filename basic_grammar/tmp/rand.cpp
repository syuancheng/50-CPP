#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;


int main() {

    for (size_t i = 0; i < 100; i++)
    {
        auto v1 = rand() % 3;
        cout << "v1: " << v1 <<endl;
    }

    return 0;
}