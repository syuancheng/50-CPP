//
// Created by Siyuan Cheng on 2022/4/21.
//

#include <iostream>
using namespace std;
class A {
    int x;
public:
    A(int i=0) {
        x=i;
        cout << "A-----"<<x<<endl;
    }
};
class B {
    int y;
public:
    B(int i) {
        y=i;
        cout << "B-----"<<y<<endl;
    }
};
class C {
    int z;
public:
    C(int i) {
        z=i;
        cout << "C-----"<<z<<endl;
    }
};
class D : public B{
public:
    C c1, c2;
    A *a1 = new A(10);
    A a0,a4;
    D( ) : a4(4),c2(2),c1(1),B(1) {
        cout << "D-----5"<<endl;
    }
};
int main(){
    D d;
    system("pause");
}
/**
* B: 基类优先，剩余按照顺序，派生类本身最后
 * 析构正好相反
*/