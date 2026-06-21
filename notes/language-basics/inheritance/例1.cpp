#include<iostream>
using namespace std;

class A {
public:
    void vf() {
        cout<<"I come from class A"<<endl;	}
};

class B: public A{};

class C: public A{};

class D: public B, public C{};

int main()
{
    D d;
    // d.vf(); // 编译错误：D 中有两个互不相关的 A 子对象，调用有歧义。
    d.B::vf();
    d.C::vf();
    return 0;
}
