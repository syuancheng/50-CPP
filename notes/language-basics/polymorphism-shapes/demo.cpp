#include <iostream>
using namespace std;

// 抽象类
class Shape
{
public:
    virtual ~Shape() = default;
    virtual double Area() const { return 0;}// 子类方法实现不一致加上virtual
    virtual int Number() const { return 0;}
    virtual void Show() const {}
    virtual double getLen() const { return 0;}
    virtual void setLen(double) {}
    virtual int getColor() const {return _color;}
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
    int Number() const override {
        return 4;
    }
    void Show() const override { cout << "Square" << endl; }
    double Area() const override
    {
        return _len*_len;
    }
    void setLen(double len) override{
        _len = len;
    }
    double getLen() const override{
        return _len;
    }
    int getColor() const override{
        return 100;
    }
private:
    double _len;
};


class Circle : public Shape
{
public:
    Circle(double radius) :_radius(radius) {}
    int Number() const override {
        return 1;
    }
    void Show() const override { cout << "Circle" << endl; }
    double Area() const override
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
    int Number() const override {
        return 3;
    }
    void Show() const override { cout << "Triangle" << endl; }
    double Area() const override
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
