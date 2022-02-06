#include <iostream>

using namespace std;

int main() {

    //string and char
    char *cp = "Hello World!!!";
    cout<<"1 "<<cp<<endl;
    char noNull[] = {'H', 'i', '\0'};
    char *ptr = noNull;

    cout<<*ptr<<endl; //H, noNull 本质是指向第一个char元素的指针。 所以一个char数组的名字就是一个char指针 它指向的是第一个元素。
    cout<<"0 "<<*cp<<endl; //H
    cout<<noNull<<endl;

    //string operation
    // string word;
    // while (cin >> word)
    // {
    //     cout<<word<<endl;
    // }
    // string line;
    // while (getline(cin, line)) //getline 没有空格的限制
    // {
    //     if (!line.empty())
    //     {
    //         cout<<line<<endl;
    //     }
    // }
    

    string str("some string");
    for (auto c : str)
    {
        cout<<c<<endl;
    }
    
    //统计字符串中标点的个数
    string s("Hello world!!!");
    decltype(s.size()) punct_cnt = 0;
    for (auto c : s)
    {
        if (ispunct(c))
        {
           ++punct_cnt;
        }
    }
    cout<<punct_cnt
        <<" punctuation characters in " << s << endl;

    //改变字符串中的值
    string s1("Hello World!!!");
    for (auto &c : s1)
    {
        c = toupper(c);
    }
    cout<<s1<<endl;
    


    return 0;
}