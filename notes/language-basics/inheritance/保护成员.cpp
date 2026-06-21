/*
基类中protected的成员
类内部：可以访问
类的使用者：不能访问
类的派生类成员：可以访问
*/
#include <iostream>
class B
{
private:
    [[maybe_unused]] int i;
protected:
    int j;
public:
    int k;
};
class D: public B
{
public:
    void f()
    {
        // i = 1; // 编译错误：派生类不能访问基类的 private 成员。
        j = 2;    // 派生类可以访问基类的 protected 成员。
        k = 3;
    }
};
int main()
{
    B b;
    // b.i = 1; // 编译错误：类外不能访问 private 成员。
    // b.j = 2; // 编译错误：类外不能访问 protected 成员。
    b.k = 3;
    std::cout << b.k << '\n';
    return 0;
}
