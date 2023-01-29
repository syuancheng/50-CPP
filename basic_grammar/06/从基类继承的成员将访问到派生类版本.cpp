#include <iostream>
using namespace std;
class B{
public:
    void f(){ g(); }
    virtual void g(){ cout << "B::g"; }
};
class D : public B{
public:
//    void g(){ cout << "D::g\n"; }
    void g() override{ cout << "D::g\n";}
};
int main(){
    D d;
    d.f(); //子类可以调用父类的成员
    system("pause");
    return 0;
}