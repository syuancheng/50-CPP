#include <iostream>

using namespace std;

int main(){
    string country = "syuan";

    transform(country.begin(), country.end(), country.begin(), toupper);
    cout<<"After Upper: "<<country<<endl;

    return 0;
}