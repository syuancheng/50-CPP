#include <iostream>

using namespace std;

template<class T, int MAXSIZE>
class Stack {
private:
    T elem[MAXSIZE];
    int top;
public:
    Stack(){top=0;};
    void push(T e);
    T pop();
    bool empty() {
        if (top <= -1)
        {
            return 1;
        } else {
            return 0;
        }
    }
    void setEmpty() {
        top = -1;
    }
    bool full() {
        if (top >= MAXSIZE)
        {
            return 1;
        } else {
            return 0;
        }
    }
};

/*
template <模板参数列表> 
返回值类型 类模板名<模板参数名表>::成员函数名 (参数列表){};
*/
template<class T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(T e)
{
    if (full())
    {
        cout<<"栈已满，不能再添加元素了！";
        return;
    }
    elem[++top] = e;
}


template<class T, int MAXSIZE>
T Stack<T, MAXSIZE>::pop() {
    if (empty())
    {
        cout<<"栈已空，不能再弹出元素了！"<<endl;
        return 0;
    }
    return elem[top--];
}

int main(int argc, char const *argv[]) {

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

    system("pause");
    return 0;
}