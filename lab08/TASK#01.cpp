#include <iostream>
#include <fstream>
using namespace std;
#include "MyDoublyLinkedList.h"


int main()
{
    MyDoublyLinkedList<int> dll;

    cout << "starting State" << endl;
    dll.display();

    cout << endl;
    cout << "Remove Empty " << endl;
    dll.removeFromFirst();
    dll.removeFromLast();
    cout << endl;


    cout << " InsertAtFirst" << endl;;
    dll.insertAtFirst(10);
    dll.display();

    dll.insertAtFirst(20);
    dll.insertAtFirst(30);
    dll.display();

    cout << endl;

    cout << "InsertAtLast" << endl;
    dll.insertAtLast(40);
    dll.insertAtLast(50);
    dll.display();

    cout << endl;
    cout << "RemoveFromFirst" << endl;
    cout << "Removed: " << dll.removeFromFirst() << endl;
    dll.display();

    cout << "Removed: " << dll.removeFromFirst() << endl;
    dll.display();
    cout << endl;

    cout << "RemoveFromLast";
    cout << "Removed: " << dll.removeFromLast() << endl;
    dll.display();

    cout << "Removed: " << dll.removeFromLast() << endl;
    dll.display();

    cout << endl;
    cout << endl;

    dll.insertAtLast(1);
    dll.insertAtLast(2);
    dll.insertAtLast(3);
    dll.insertAtLast(4);
    dll.display();

    cout << endl;

    cout << "opy Constructor"<<endl;

    MyDoublyLinkedList<int> copyList(dll);
    cout << "Original: ";
    dll.display();

    cout << "Copy: ";
    copyList.display();


    dll.removeFromFirst();
    dll.removeFromLast();

    cout << "After modifying" <<endl;
    cout << "Original: ";
    dll.display();

    cout << "Copy: ";
    copyList.display();


    return 0;
}