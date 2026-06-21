#include <iostream>

using namespace std;

uint64_t now() {
    time_t rowtime;
    return time(&rowtime);
}

int main() {

    cout<<"TIme: "<<now()<<endl;

    return 0;
}