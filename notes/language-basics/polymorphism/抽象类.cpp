#include<iostream>
using namespace std;
class Figure{
protected:
    double x,y;
public:
    virtual ~Figure() = default;
    void set(double i, double j){
        x=i;y=j;
    }
    virtual void area()=0;
    virtual void test() {cout <<"Test pure"<<endl;}
};

class Trianle:public Figure{
public:
    void area() override {
        cout<<"三角形面积："<<x*y*0.5<<endl;
    }
    void test() override {cout <<"这是三角形"<<endl;}
};
class Rectangle:public Figure{
public:
    void area() override {
        cout<<"这是矩形，它的面积是："<<x*y<<endl;
    }
    void test() override {cout <<"这是矩形"<<endl;}
};

int main()
{
    //定义抽象类指针
    Figure *pF=nullptr;
//    Figure f1; //抽象类不能被实例化

    Trianle t;
    t.set(10,20);
    pF=&t;
    pF->area();
    pF->test();

    Rectangle r;
    r.set(10,20);
    pF=&r;
    pF->area();
    pF->test();
    //定义抽象类引用

    Figure &rF=t;
    rF.set(20,20);
    rF.area();
    rF.test();
    return 0;
}
