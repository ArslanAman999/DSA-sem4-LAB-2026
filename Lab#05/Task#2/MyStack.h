#pragma once
#include"Stack.h"
#include"myLinkedList.h"
class MyStack : public Stack
{
private:
    myLinkedList list;

public:
    MyStack(int _count = 0) : Stack() { count = _count; };
    MyStack(const MyStack& ma) : Stack(ma) {};

    void push(int v);
    bool pop(int& v);
    int top();
};

void MyStack::push(int v)
{
    list.insertAtFirst(v);  // stack push
    count++;
}

bool MyStack::pop(int& v)
{
    if (!isEmpty())
    {
        v = list.removeFromFirst();  // stack pop
        count--;
        return true;
    }
    return false;
}

int MyStack::top()
{
    if (!isEmpty())
    {
        int temp = list.removeFromFirst();
        list.insertAtFirst(temp); // restore after checking
        return temp;
    }
    return -1;
}

