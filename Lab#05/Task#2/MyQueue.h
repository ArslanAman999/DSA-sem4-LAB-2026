#pragma once
#include"Queue.h"
#include"myLinkedList.h"
class MyQueue : public Queue
{
private:
    myLinkedList list;

public:
    MyQueue(int _count = 0) : Queue() { count = _count; };
    MyQueue(const MyQueue& ma) : Queue(ma) {};

    void enqueue(const int& value)
    {
        list.insertAtLast(value);
    }
    bool dequeue(int& v)
    {
        if (isEmpty())
        {
            cout << "MyQueue is EMPTY! Cannot remove." << endl;
            return false;
        }

        v = list.removeFromFirst();
        return true;
    }
};
