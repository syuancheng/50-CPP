#include <iostream>

using namespace std;

/*
C++的引用是右值引用

int ival = 100;
int &refIval  = ival;  //refIval是指向ival的另一个名字。

wrong:
int &refIval2;  //应用必须被初始化。
初始化变量时， 引用会被拷贝到新建的对象中。  在定义引用时， 程序把引用和他的初始值绑定在一起。一旦初始化完成，应用将和它的初始对象
一直绑定在一起。因为无法让引用重新绑定到另外*一个对象，所以引用必须初始化

引用并非对象，他只是为一个已经存在的对象所起的另一个名字
*/

int main() {
    int ival = 1024;
    int &refIval = ival;
    cout<<ival<<endl;    //1024
    cout<<refIval<<endl; //1024

    //change ival
    ival = 100;
    cout<<ival<<endl;   //100
    cout<<refIval<<endl;//100

    //change refIval
    refIval = 24;
    cout<<ival<<endl;    //24
    cout<<refIval<<endl; //24

    //permier test
    int i, &ri = i;
    i = 5; ri = 10;
    cout<<i<<" "<<ri<<endl; // 10 10

    return 0;
}