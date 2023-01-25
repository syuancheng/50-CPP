#include <iostream>
using namespace std;

// 抽象类
class Shape
{
public:
    virtual double Area() const { return 0;}// 子类方法实现不一致加上virtual
    virtual int Number(){ return 0;}
    virtual void Show(){}
    virtual double getLen(){ return 0;}
    virtual void setLen(double len){}
    virtual int getColor(){return _color;}
    void SetColor(int color) { _color = color; }
    void Display()
    {
        cout << Area() << endl;
    }
private:
    int _color= 10;
};


class Square: public Shape
{
public:
    Square(double len) :_len(len) { }
    int Number(){
        return 4;
    }
    void Show() { cout << "Square" << endl; }
    double Area() const
    {
        return _len*_len;
    }
    void setLen(double len) override{
        _len = len;
    }
    double getLen() override{
        return _len;
    }
    int getColor() override{
        return 100;
    }
private:
    double _len;
};


class Circle : public Shape
{
public:
    Circle(double radius) :_radius(radius) {}
    int Number(){
        return 1;
    }
    void Show() { cout << "Circle" << endl; }
    double Area() const
    {
        return 3.1415926*_radius*_radius;
    }

private:
    double _radius;
};

class Triangle : public Shape
{
public:
    Triangle(double len, double height) :_len(len), _height(height){}
    int Number(){
        return 3;
    }
    void Show() { cout << "Triangle" << endl; }
    double Area() const
    {
        return 0.5*_len*_height;
    }

private:
    double _len;
    double _height;
};

int main()
{
    Square s1(2.0);
    cout<< "s1: " << s1.Area()<<endl;
    Shape& sp = s1;
    cout<< "sp: " << sp.Area()<<endl;
    sp.setLen(8.0);
    cout<<"len: " << sp.getLen()<<endl;
    cout<<"len: " << s1.getLen()<<endl;

    Circle c1(2.0);
    cout<< "c1: "<<c1.getLen()<<endl;

    Square s2(3.0);
    cout<<"s2: "<<s2.getColor()<<endl;

    Shape& p2 = s2;
    p2.SetColor(23);
    cout<<"p2: "<<p2.getColor()<<endl;
    cout<<"s2: "<<s2.getColor()<<endl;

    Shape p3;
    cout<<"p3: "<<p3.getColor()<<endl;
    p3.SetColor(23);
    cout<<"p3: "<<p3.getColor()<<endl;

//    cout<< "s1: " << s1.Area()<<endl;
//    cout<< "sp: " << sp.Area()<<endl;

//    Square s1(2.0);
//    Circle c1(2.0);
//    Triangle t1(3.0,4.0);
//
//    Shape* shapes[3];
//    shapes[0] = &s1;
//    shapes[1] = &c1;
//    shapes[2] = &t1;
//
//    for (int i = 0; i < 3; ++i) {
////        shapes[i]->Display();
//        shapes[i]->Show();
//        cout<<"Area is: " << shapes[i]->Area() << endl;
//        cout<<"Number is: "<< shapes[i]->Number() << endl;
//
//    }

//    // 面对变化，尽可能少修改原有的逻辑，要扩充逻辑
//    const int shapeNum = 3;
//
//    Square s1(2.0);
//    s1.SetColor(1);
//    Circle   c1(2.0);
//    Triangle t1(2.0, 3.0);
//
//    Shape* shapes[shapeNum];
//    shapes[0] = &s1;
//    shapes[1] = &c1;
//    shapes[2] = &t1;
//
//    for (unsigned int index = 0; index < shapeNum; index++)
//    {
//        shapes[index]->Display();
//    }
//
//    cout << endl;
//    cout << sizeof(s1) << endl;

    return 0;

}