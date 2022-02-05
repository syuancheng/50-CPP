#include <iostream>

using namespace std;

/*
指针
指针和引用都实现了对其他对象的间接访问。但是还有一些不同
1. 指针本身就是一个对象，允许对指针进行赋值和拷贝。在生命周期内，他可以指向几个不同的对象。
2. 指针不需要在定义的时候赋初值，和内置类型一样，指针如果没有初始化，指针也将拥有一个不确定值。




*/



int main() {

    int ival = 42;
    int *p = &ival; //p存放变量ival的地址。
    cout<<ival<<endl; //42
    cout<<p<<endl;  //0x324f3ff9b4
    cout<<*p<<endl; //42

    *p = 2;
    cout<<ival<<endl;
    cout<<*p<<endl;




    return 0;
}