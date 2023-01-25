#include <iostream>
#include <vector>

using namespace std;

int main(){
    //1.Define
    cout<<"1. Define a vector:\n";
    vector<int> v1;//空vector

    vector<int> v2(v1);
    vector<int> v3 = v1;
    
    vector<int> v4(3, 8);//3个元素每个都是8
    vector<int> v7(10);//10个元素， 每个都是0

    vector<int> v5{1,2,3,4,5};
    vector<int> v6 = {5,4,3,2,1};

    //2.添加元素
    cout<<"2. add element\n";
    vector<int> vec1;//如果不知道会加入多少个元素， 那么定义的时候不要指定容量
    for (int i = 0; i != 10; ++i)
    {
        vec1.push_back(i);
    }    

    cout<< "Length: "<< vec1.size()<<endl;
    cout<< "Test: " << vec1[1];

    //TODO 范围for语句问题
    //3. For range loop
    for (auto &i : vec1)
    {
        // vec1.erase();
        vec1.push_back(91); //err 范围for语句体内， 不应该改变所遍历序列的大小。
    }

    //empty
    if (v1.empty()) 
    {
        cout<<v1.empty()<<endl;
    }
    //size
    auto siz1 = vec1.size();
    //[n] 返回第n个位置上元素的引用


    //如果vec1是空的话，下面是错误的
    for (decltype(vec1.size()) i = 0; i < 10; ++i)
    {
        vec1[i] = i; //
    }


    //Example:体现c++的简洁性
    //以10分为一个分数段统计成绩的数量， 0-9 10-19... 100
    vector<unsigned> scores(11, 0); //11个分数段， 长度为0
    unsigned grade;
    while (cin>>grade)
    {
        if (grade<=100)
        {
            ++scores[grade/10];
            //等价于
            // auto ind = scores[grade/10];
            // scores[ind] = scores[ind] + 1;
        }
        
    }
    
    



    



    return 0;
}