//
// Created by Siyuan Cheng on 2022/6/15.
//

#ifndef CHAPTER4_STACK_H
#define CHAPTER4_STACK_H


class Stack {
    Stack();
    virtual ~Stack();
    virtual int pop()=0; //remove the first element, and remove it
    virtual void push()=0;
    virtual int size()=0;
    virtual bool empty()=0;
    virtual bool full()=0;
    virtual int peek()=0;//return the first element, but don't remove it
    virtual void print()=0;
};

class LIFO_Stack : public Stack{

};

class Peekback_Stack : public Stack{

};


#endif //CHAPTER4_STACK_H
