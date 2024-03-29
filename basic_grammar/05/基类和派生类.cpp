#include <iostream>

using namespace std;


/**
* 基类对象与派生类对象之间存在赋值相容性。包括以下几种情况：
 * 把派生类对象赋值给基类对象。
 * 把派生类对象的地址赋值给基类指针。
 * 用派生类对象初始化基类对象的引用。
 *
 * 反之则不行，即不能把基类对象赋值给派生类对象；
 * 不能把基类对象的地址赋值给派生类对象的指针；
 * 也不能把基类对象作为派生对象的引用。
*/

class A {
    int a;
public:
    void setA(int x){a = x;}
    int getA(){return a;}
};

class B : public A {
    int b;
public:
    int c;
    void setB(int x){b=x;}
    int getB(){return b;}
};

void f1(A a, int x)
{ a.setA(x); }
void f2(A *pA, int x)
{ pA->setA(x); }
void f3(A &rA, int x)
{ rA.setA(x); }

int main() {
    A a1,*pA;
    B b1,*pB;
    a1.setA(1);
    b1.setA(2);
    //0. 把派生类对象赋值给基类对象。
    a1=b1;
    cout<<a1.getA()<<endl;
    cout<<b1.getA()<<endl;
    a1.setA(10);
    cout<<a1.getA()<<endl;
    cout<<b1.getA()<<endl;

    //2. 把派生类对象的地址赋值给基类指针。
    pA=&b1;
    pA->setA(20);
    cout<<pA->getA()<<endl;
    cout<<b1.getA()<<endl;

    //3. 用派生类对象初始化基类对象的引用。
    A &ra=b1;
    ra.setA(30);
    cout<<pA->getA()<<endl;
    cout<<b1.getA()<<endl;

}