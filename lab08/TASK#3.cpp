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

// FREQUNCY 

bool isFound(MyStack<int> st, int value)
{
    if (st.isEmpty())
    {
        return false;
    }
    int v = 0;
    st.pop(v);

    if (v == value)
    {
        return true;
    }

    return isFound(st, value);
}

int singleFrequency(MyStack<int> st, int value)
{
    if (st.isEmpty())
    {
        return 0;
    }
    int v = 0;
    st.pop(v);
  //cout << v;

    if (v == value)
    {
        return singleFrequency(st,value) + 1;
    }
    else
    {
        return singleFrequency(st, value);
    }
}

void removeDuplicates(MyStack<int>& s)
{
    if (s.isEmpty())
    {
        return;
    }

    int x = 0;
    s.pop(x);
    removeDuplicates(s);

    if (!isFound(s, x))
    {
        s.push(x);
    }

}

MyStack<int> frequency(MyStack<int>& s)
{
    static bool playOnce = true;
    static MyStack<int> f(20);
    static MyStack<int> temp(20);

    if (playOnce)
    {
        copyStack(s,temp);
        removeDuplicates(temp);
        playOnce = false;
    }

    if (temp.isEmpty())
    {
        static MyStack<int> r;
        return r;
    }

    int x = 0;
    temp.pop(x);

    frequency(s);

    int valueCount = singleFrequency(s, x);
    f.push(valueCount);

    return f;
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

    //display(s1);
    
    cout << "Original Stack: ";
    display(s1);


    MyStack<int> copied(20);

    copyStack(s1, copied);

    cout << "Copied Stack: ";
    display(copied);

    
   cout << "Size of Stack = " << getSize(s1) << endl;


   cout << "Maximum Value = " << maxValue(s1) << endl;

    /*if (isFound(s1, 33)) {cout << "Found" << endl;}
    else { cout << " NOT Found" << endl; }
    display(s1);

    cout << singleFrequency(s1,3) << endl

    removeDuplicates(copied);
    display(copied);*/

   cout << "Frequncy of numbers in stack"<< endl;


    MyStack<int> s2(20);
    s2 = frequency(copied);
    removeDuplicates(copied);

    cout << "Values :\t"; 
    display(copied);

    cout << "frequency :\t"; 
    display(s2);

    return 0;
}
