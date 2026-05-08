#include<iostream>
#include"MyStack.h"
using namespace std;



void copyStack(MyStack<int> src, MyStack<int>& copy)
{
    if (src.isEmpty())
    {
        return;
    }

    int value;
    src.pop(value);

    copy.push(value);

    copyStack(src, copy);
}


void display(MyStack<int> st)
{
    if (st.isEmpty())
    {
        cout << endl;
        return;
    }

    int value;
    st.pop(value);

    cout << value << " ";

    display(st);
}


int getSize(MyStack<int> st)
{
    if (st.isEmpty())
    {
        return 0;
    }

    int value;
    st.pop(value);

    return 1 + getSize(st);
}


int maxValue(MyStack<int> st)
{
    int value;
    st.pop(value);

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

int main()
{
    MyStack<int> s1(20);

    s1.push(5);
    s1.push(2);
    s1.push(5);
    s1.push(7);
    s1.push(2);
    s1.push(5);

    cout << "Original Stack: ";
    display(s1);


    MyStack<int> copied(20);

    copyStack(s1, copied);

    cout << "Copied Stack: ";
    display(copied);

    cout << "Size of Stack = "<< getSize(s1) << endl;


    cout << "Maximum Value = "<< maxValue(s1) << endl;

    return 0;
}