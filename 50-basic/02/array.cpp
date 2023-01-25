#include <iostream>

using namespace std;

int main() {
    //1.数组初始化的时候，必须确保维度（长度）是常量
    //2. 大小固定，性能好的同时相比vector失去了一些灵活性。
    // int arr[10];
    unsigned cnt = 42;
    //int arr1[cnt]; //error cnt isn't a const

    //2. 初始化
    const unsigned sz = 3;
    int ia1[sz] = {0,1,2};
    int a2[] = {0,1,2}; //also correct, length is 3.
    int a3[5] = {0, 1, 2}; //correct, equeal to {0,1,2,0,0}
    string a4[3] = {"tom", "tony"}; //correct, equal to {"tom", "tony", ""}

    //字符数组
    char b1[] = {'C', '+', '+'}; //length is 3
    char b2[] = "C++"; //length is 4, a '\0' is added the end of str repesent the string finish.

    //不允许拷贝赋值
    int c[] = {0,1,2};
    //int c1[] = c; //error

    //存放指针的数组(指针数组)
    int *ptrs1[10];

    //数组是对象，因为有数组指针和数组引用， 但是没有存放引用的数组（引用数组）
    //int &ptrs2[10]; //error

    int arr[10];
    int (*parray)[10] = &arr;
    int (&array)[10] = arr;
    //内->右->左
    int *arr1[10];
    int *(&array1)[10] = arr1; //array1是一个引用，和它绑定的是 含有10个int指针的数组。

    //数组和指针
    //在很多使用到数组名字的地方，编译器都会自动地将其替换为以为指向数组首元素的指针。
    int ia[] = {1,2,3,4,5,6,7,8,9};
    auto ia2(ia); //ia2是一个整形指针，指向ia的第一个元素，等价于：
    auto ia3(&ia[0]);
    cout<<*ia2<<endl;//1
    //怎么才能不是指针呢？ decltype关键字

    //下标和指针
    int list[] = {1,2,3,4};

    int i = list[2]; //list转为执行第一个元素的指针
                     //list[2] 得到 list+2所指的指针
    int *p = list;   //p指向list的首元素
    i = *(p+2);      //等价于i = ia[2]

    int *q = &list[2]; //q是指向list中第二个元素的指针
    int j = q[1]; //*(q+1) 是list[3] , 这里并没有修改q的指向
    int k = q[-2]; // *(q-2) 是list[0]


    return 0;
}