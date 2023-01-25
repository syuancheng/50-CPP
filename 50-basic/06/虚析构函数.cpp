//
// Created by Siyuan Cheng on 2022/4/22.
//

#include <iostream>
using namespace std;
class A{
public:
    virtual ~A(){ cout<<"call A::~A()"<<endl; }
};
class B:public A{
    char *buf;
public:
    B(int i){buf=new char[i];}
    ~B(){
        delete [] buf;
        cout<<"call B::~()"<<endl;
    }
};
int main(){
    A* a=new B(10);
    delete a;//析构顺序： 先 子类，后父类。 和构造相反
    system("pause");
    return 0;
}