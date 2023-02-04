#include <iostream>
#include <string>

int main() {

    std::cout << "Please enter your first name: ";
    //name: 局部变量，也就是说，它只存活在花括号起的程序运行期内
    //一旦程序到达了}，变量name就会被销毁，同时这个变量所占的全部内存
    //也会被系统回收用于其他用途。
    std::string name;
    std::cin >> name;

    //定义的时候必须进行初始化， 数值本身不必是一个常量。
    const std::string greeting = "Hello, " + name + "!";

    const std::string spaces(greeting.size(), ' ');
    const std::string second = "* " + spaces + " *";

    const std::string first(second.size(), '*');

    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;




    return 0;
}