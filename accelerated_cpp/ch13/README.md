### 使用继承与动态绑定

public 继承
基类的public成员也是派生类的一部分。
protected成员可以访问
private成员不可以访问


Q1:编译器如何生成派生类的对象？
1.为整个对象分配内存空间
2.调用基类构造函数以初始化对象的基类部分数据
3.有构造初始化器

Q2: Grad g 会发生什么？
1.分配可以存储5个数据元素的内存空间。
2.运行Core类的默认构造函数对g对象的Core类部分数据成员进行初始化。
3.调用Grad的默认构造函数。

Q3: Grad g(cin) 会发生什么？
1.分配可以存储5个数据元素的内存空间。
2.运行Core类的默认构造函数。
3.调用Grad(std::istream& is)构造函数为name，midterm，final和homework成员数据进行初始化。


Q3:virtual函数
grade是virtual函数，可以保证compare_grades函数执行时，将由参数的实际类型来决定调用基类or派生类的grade函数。
virtual关键字只能在类的定义中被使用。
virtual函数在程序中必须要定义。
非virtual函数可以只声明不定义。


Q4:动态绑定
```
Core c;
Grad g;
Core* p;
Core& r = g;

c.grade() //对core::grade函数静态绑定
g.grade()//对grad::grade函数动态绑定
```
多态
C++通过虚拟函数的动态绑定特性来支持多态性。
通过一个指针或者一个引用调用虚拟函数，就是一个多态调用。
引用(或指针)参数的类型是固定的，但是参数所引用(所指)的对象的类型却可以是 所引(所指)对象的类型，或是该类
派生出来的一个任何子类。

virtual ~Core() {}
函数体是空的， 因为系统会自动删除对象的成员数据。
所有通过一个指向基类的指针来删除一个派生类对象的时候，都要用到虚拟析构函数。


handle class


friend函数可以访问类的private和protected成员
把一个类声明为另一个类的firend，可以使得该类中的所有成员都成为另一个类的友员。
类B是类A的友元，那么类B可以直接访问A的私有成员。
```cpp
#include <iostream>

using namespace std;

class A
{
public:
    A(int _a):a(_a){};
    friend class B;
private:
    int a;
};

class B
{
public:
    int getb(A ca) {
        return  ca.a; 
    };
};

int main() 
{
    A a(3);
    B b;
    cout<<b.getb(a)<<endl;
    return 0;
}
```
友元关系没有继承性 假如类B是类A的友元，类C继承于类A，那么友元类B是没办法直接访问类C的私有或保护成员。

友元关系没有传递性 假如类B是类A的友元，类C是类B的友元，那么友元类C是没办法直接访问类A的私有或保护成员，也就是不存在“友元的友元”这种关系。