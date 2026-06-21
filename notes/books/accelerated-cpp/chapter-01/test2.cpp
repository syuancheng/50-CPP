#include <iostream>
#include <string>

int main() {

    std::string name = "krystal";
    std::string second = "zhung";
    std::cout << "name   value:" << name << " ,pointer:" << &name << std::endl;
    std::cout << "second value:" << second << " ,pointer:" << &second << std::endl;
    
    std::string alias = name; // different address, copy name to alias
    std::cout << "alias  value:" << alias << " ,pointer:" << &alias << std::endl;

    std::string full = name + second;
    std::cout << "full   value:" << full << " ,pointer:" << &full << std::endl;

    return 0;
}