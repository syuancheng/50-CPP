#include <iostream>
#include <random>

using namespace std;


int main() {
    std::mt19937 engine(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, 2);

    for (size_t i = 0; i < 100; i++)
    {
        const int v1 = distribution(engine);
        cout << "v1: " << v1 <<endl;
    }

    return 0;
}
