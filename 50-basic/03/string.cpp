#include <iostream>

using namespace std;

int main() {

    //1.定义和初始化string对象
    cout<<"1. define and declare string\n";
    char *cp = "Hello World!!!";//以空字符串结束的数组
    cout<<cp<<endl; //Hello World!!!
    cout<<*cp<<endl;//H

    
    char noNull[] = {'H', 'i', '\0'};
    char *ptr = noNull;

    cout<<*ptr<<endl; //H, noNull 本质是指向第一个char元素的指针。 所以一个char数组的名字就是一个char指针 它指向的是第一个元素。
    cout<<ptr<<endl; //Hi,
    cout<<noNull<<endl; //Hi
    cout<<*noNull<<endl; //H

    //2. string input by keyboard
    cout<<"2. Input a string by keyboard.\n";
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
    
    //3. 遍历一个string
    cout<<"3. Loop a string.\n";
    string str("some string");
    for (auto c : str)
    {
        cout<<c<<endl;
    }
    //修改内容
    for (auto &c : str)
    {
        cout<<c<<endl;
    }
    //下标遍历
    for (decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); ++index)
    {
        str[index] = toupper(str[index]);//返回的是引用
    }
    cout<<str<<endl;
    

    //4. 字符串查找，定位
    //有很多 isxxxx(c)可以用来判断特殊字符
    
    //统计字符串中标点的个数
    cout<<"4. \n";
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
    //5. 修改字符串中的字符
    string s1("Hello World!!!");
    for (auto &c : s1)
    {
        c = toupper(c);
        // c = tolower(c);
    }
    cout<<s1<<endl;
    //使用下标运算符[]， 返回的是该位置上字符的引用
    string name("Siyuan cheng");
    name[7] = toupper(name[7]);
    cout<<name<<endl;

     for (decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); ++index)
    {
        str[index] = toupper(str[index]);//返回的是引用
    }
    cout<<str<<endl;

    //6. substr操作
    cout<<"6. substr operation\n";
    string s6("hello world");
    string s61 = s6.substr(0,5); //[0, 5)
    cout<<s61<<endl;
    string s62 = s6.substr(5); // >=5
    cout<<s62<<endl;

    //7.insert 和 erase
    cout<<"7. insert and erase operation\n";
    string s63 = s6.insert(s6.size(), 5, '!');//hello world!!!!!， 从下标开始，加入5个！
    cout<<s63<<endl;
    string s64 = s6.erase(5, 2);//从下标为5的位置开始， 删除两个字符
    cout<<s64<<endl;

    string s7("hello beijing");
    cout<<s7.insert(0, s6)<<endl; //s7从0位置加入s6.
    cout<<s7.insert(0, s6, 0, 5)<<endl;//s7从0位置加入s6当中的前5个字符

    cout<<"8. append and replace operation\n";
    //8. assign append and replace operation
    //assign 总是直接全部替换， append总是给后面加， 不需要设定位置
    string s8("C++ Primer");
    cout<<s8.append(" 4th Ed.")<<endl; //在s8后面加上一个字符串

    cout<<s8.replace(11, 3, "5th")<<endl; //将s8从11开始的三个字符更换为5th

    string s9("krystal zheng");
    s9.assign("Jessica");//直接把s9替换为Jessica
    cout<<s9<<endl;


    //9. 查找
    cout<<"9. Search operation.\n";
    string fx("KrystalZheng");
    auto posl = fx.find("Krystal");
    cout<<posl<<endl; //0
    auto posl1 = fx.find("krystal"); //大小写敏感
    cout<<posl1<<endl;


    string nums("4545351375"), fx1("Je7ss");
    auto pos = nums.find_first_of(fx1);//查找nums中， 第一个在fx1中的字符的位置
    cout<<pos<<endl;//8, fx1中任何一个字符在nums中出现的第一个位置
    auto pos1 = nums.find_first_not_of(fx1); //查找nums中，第一个不在fx1中 字符的位置
    cout<<pos1<<endl;//0

    string river("Mississippi");
    auto first_pos = river.find("is");
    cout<<first_pos<<endl;//1
    auto last_pos = river.rfind("is");
    cout<<last_pos<<endl;//4


    //10. 转换
    int i = 42;
    string s_str = to_string(i);
    cout<<s_str<<endl;
    double dd = stod(s_str);//将字符串转为浮点数
    cout<<dd<<endl;

    string s10 = "pi = 3.14";
    auto dd1 = stod(s10.substr(s10.find_first_of("+-.0123456789")));
    cout<<dd1<<endl;


    //11. size, empty, swap
    string stra("jessica"), strb("krystal");
    cout<<stra.empty()<<endl;
    cout<<stra.size()<<endl;
    swap(stra, strb);
    cout<<"a: "<<stra<<endl;
    cout<<"b: "<<strb<<endl;
    stra.swap(strb);
    cout<<"a: "<<stra<<endl;
    cout<<"b: "<<strb<<endl;







    return 0;
}