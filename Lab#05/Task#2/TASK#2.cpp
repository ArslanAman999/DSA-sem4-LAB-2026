#include <iostream>
using namespace std;
#include"MyStack.h"
#include"MyQueue.h"


/*
for Stack 
Pop : use insert art first 
push :use remove from first
top: removefrom first store in varibale and then insert at first

for queue 
dequeue : use insert at last 
enqueue :use remove from first

*/

int main()
{
    cout << "===== STACK TEST =====\n";

    MyStack s;

    cout << "Is stack empty? " << s.isEmpty() << endl;

    cout << "\nPushing elements: 10, 20, 30\n";
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Is stack empty? " << s.isEmpty() << endl;

    int val =0;

    cout << endl;
    cout << "\nPopping elements:" << endl;
    while (!s.isEmpty())
    {
        s.pop(val);
        cout << val << " ";
    }

    cout << endl;
    cout << "Is stack empty after pop? " << s.isEmpty() << endl;


    // ================= QUEUE TEST =================
    cout << endl;
    cout << endl;
    cout << "===== QUEUE TEST =====" << endl;

    MyQueue q;

    cout << "Is queue empty? " << q.isEmpty() << endl;

    cout << endl;
    cout << "Enqueuing elements: 5, 15, 25" << endl;
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);

    cout << "Is queue empty? " << q.isEmpty() << endl;

    cout << endl;
    cout << "Dequeuing elements:" << endl;
    while (!q.isEmpty())
    {
        q.dequeue(val);
        cout << val << " ";
    }

    cout << endl;
    cout << "Is queue empty after dequeue? " << q.isEmpty() << endl;

    return 0;
}