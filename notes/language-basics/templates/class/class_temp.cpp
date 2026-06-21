#include <iostream>

using namespace std;

template<class T, int MAXSIZE>
class Stack {
private:
    T elem[MAXSIZE];
    int size_;
public:
    Stack(): size_(0) {}
    bool push(const T& value);
    T pop();
    bool empty() const { return size_ == 0; }
    void setEmpty() noexcept { size_ = 0; }
    bool full() const { return size_ == MAXSIZE; }
};

/*
template <模板参数列表> 
返回值类型 类模板名<模板参数名表>::成员函数名 (参数列表){};
*/
template<class T, int MAXSIZE>
bool Stack<T, MAXSIZE>::push(const T& value)
{
    if (full())
    {
        return false;
    }
    elem[size_++] = value;
    return true;
}


template<class T, int MAXSIZE>
T Stack<T, MAXSIZE>::pop() {
    if (empty())
    {
        cout<<"栈已空，不能再弹出元素了！"<<endl;
        return T{};
    }
    return elem[--size_];
}

int main() {

    Stack<int, 10> iStack;
    Stack<char, 10> cStack;
    iStack.setEmpty();
    cStack.setEmpty();
    cout<<"-------intStack----\n";

    int i;
    for (i = 0; i < 11; i++)
    {
        iStack.push(i);
    }
    
    for (i = 1; i < 11; i++)
    {
        cout<<iStack.pop()<<"\t";
    }
    cout<<"\n\n-------charStack----\n";

    cStack.push('A');	cStack.push('B');
    cStack.push('C'); 	cStack.push('D');
    cStack.push('E');

    for(i=1;i<6;i++) {
        cout<<cStack.pop()<<"\t";
    }
    
    cout<<endl;

    return 0;
}
