#include<iostream>
#include"MyQueue.h"
using namespace std;

void copyQueue(MyQueue<int> src, MyQueue<int>& copy)
{
    if (src.isEmpty())
    {
        return;
    }

    int v = src.dequeue();

    copy.enqueue(v);

    copyQueue(src, copy);
}
void display(MyQueue<int> as)
{
    if (as.isEmpty())
    {
        return;
    }

    int v = as.dequeue();

    cout << v << " ";

    display(as);
}
int getSize(MyQueue<int> st)
{
    if (st.isEmpty())
    {
        return 0;
    }

    int value = st.dequeue();

    return 1 + getSize(st);
}
int maxValue(MyQueue<int> st)
{
    int value =  st.dequeue();

    if (st.isEmpty())
    {
        return value;
    }

    int mx = maxValue(st);

    if (value > mx)
    {
        return value;
    }

    return mx;
}

// FREQUNCY 

bool isFound(MyQueue<int> st, int value)
{
    if (st.isEmpty())
    {
        return false;
    }
    int v = st.dequeue();

    if (v == value)
    {
        return true;
    }

    return isFound(st, value);
}

int singleFrequency(MyQueue<int> st, int value)
{
    if (st.isEmpty())
    {
        return 0;
    }
    int v = st.dequeue();
    //cout << v;

    if (v == value)
    {
        return singleFrequency(st, value) + 1;
    }
    else
    {
        return singleFrequency(st, value);
    }
}

void removeDuplicates(MyQueue<int>& s)
{
    if (s.isEmpty())
    {
        return;
    }

    int x = s.dequeue();
    removeDuplicates(s);

    if (!isFound(s, x))
    {
        s.enqueue(x);
    }

}

MyQueue<int> frequency(MyQueue<int>& s)
{
    static bool playOnce = true;
    static MyQueue<int> f(20);
    static MyQueue<int> temp(20);

    if (playOnce)
    {
        copyQueue(s, temp);
        removeDuplicates(temp);
        playOnce = false;
    }

    if (temp.isEmpty())
    {
        MyQueue<int> r(1);
        return r;
    }

    int x = temp.dequeue();

    frequency(s);

    int valueCount = singleFrequency(s, x);
    f.enqueue(valueCount);

    return f;
}

int main()
{
    MyQueue<int> s1(20);

    s1.enqueue(5);
    s1.enqueue(9);
    s1.enqueue(5);
    s1.enqueue(3);
    s1.enqueue(3);
    s1.enqueue(5);

    //display(s1);

    cout << "Original Queue: ";
    display(s1);
    cout << endl;
    cout << endl;
    cout << endl;
    //s1.display(cout);

    MyQueue<int> copied(20);

    copyQueue(s1, copied);

    cout << "Copied Queue: ";
    display(copied);


    cout << "Size of queue = " << getSize(s1) << endl;


    cout << "Maximum Value = " << maxValue(s1) << endl;

    /*if (isFound(s1, 33)) {cout << "Found" << endl;}
    else { cout << " NOT Found" << endl; }
    display(s1);

    cout << singleFrequency(s1, 3) << endl;

    removeDuplicates(copied);
    display(copied);*/

    cout << "Frequncy of numbers in Queue" << endl;


    MyQueue<int> s2(20);
    s2 = frequency(copied);
    removeDuplicates(copied);

    cout << "Values :\t"<<endl;
    display(copied);

    cout << "frequency :\t";
    display(s2);

    return 0;
}