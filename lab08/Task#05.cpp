#include<iostream>
#include"MyLinkedList.h"
using namespace std;


void copyList(myLinkedList<int> src, myLinkedList<int>& copy)
{
    if (src.isEmpty())
    {
        return;
    }

    int value = src.removeFromFirst();

    copy.insertAtFirst(value);

    copyList(src, copy);
}
void display(myLinkedList<int> st)
{
    if (st.isEmpty())
    {
        cout << endl;
        return;
    }

    int value = st.removeFromFirst();

    cout << value << " ";

    display(st);
}
int getSize(myLinkedList<int> st)
{
    if (st.isEmpty())
    {
        return 0;
    }
    st.removeFromFirst();

    return 1 + getSize(st);
}
int maxValue(myLinkedList<int> st)
{
    int value = st.removeFromFirst();

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

bool isFound(myLinkedList<int> st, int value)
{
    if (st.isEmpty())
    {
        return false;
    }
    int v = st.removeFromFirst();

    if (v == value)
    {
        return true;
    }

    return isFound(st, value);
}

int singleFrequency(myLinkedList<int> st, int value)
{
    if (st.isEmpty())
    {
        return 0;
    }
    int v = st.removeFromFirst();

    if (v == value)
    {
        return singleFrequency(st, value) + 1;
    }
    else
    {
        return singleFrequency(st, value);
    }
}

void removeDuplicates(myLinkedList<int>& s)
{
    if (s.isEmpty())
    {
        return;
    }

    int x = s.removeFromFirst();
    removeDuplicates(s);

    if (!isFound(s, x))
    {
        s.insertAtFirst(x);
    }

}

myLinkedList<int> frequency(myLinkedList<int>& s)
{
    static bool playOnce = true;
    static myLinkedList<int> f;
    static myLinkedList<int> temp;

    if (playOnce)
    {
        copyList(s, temp);
        removeDuplicates(temp);
        playOnce = false;
        cout << "val : frq" << endl;

    }

    if (temp.isEmpty())
    {
        myLinkedList<int> r;
        return r;
    }

    int x = temp.removeFromFirst();

    frequency(s);

    int valueCount = singleFrequency(s, x);
    cout << x << " : " << valueCount << endl;
    f.insertAtFirst(valueCount);

    return f;
}

int main()
{
    myLinkedList<int> s1;

    s1.insertAtFirst(5);
    s1.insertAtFirst(2);
    s1.insertAtFirst(5);
    s1.insertAtFirst(7);
    s1.insertAtFirst(2);
    s1.insertAtFirst(5);

    //display(s1);

    cout << "Original Stack: ";
    display(s1);


    myLinkedList<int> copied;

    copyList(s1, copied);

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

    cout << "Frequncy of numbers in stack" << endl;


    myLinkedList<int> s2;
    frequency(copied);
    removeDuplicates(copied);


    return 0;
}