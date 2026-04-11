#include <iostream>
using namespace std;
#include "FirstOnlyLinkedList.h"
#include "myFirstOnlyLinkedList.h"

/*
getSize():
Traverses the list from first node to last node and incement a count variable.

get(pos):
Traverses to given position and returns its value.

put(pos, value):
Traverses to given position and update its value.

swap(xi, yi):
we Trivarse and store the address of the the 2 positions after that we simpley
rplace there value as we already have their address

sort(asc):
we use buuble sort
*/

int myFirstOnlyLinkedList::getSize()
{
    int count = 0;
    Node* temp = first;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int myFirstOnlyLinkedList::get(int pos)
{
    Node* temp = first;
    int index = 0;

    while (temp != nullptr)
    {
        if (index == pos)
        {
            return temp->data;
        }

        temp = temp->next;
        index++;
    }

    return -9999; // invalid position
}

void myFirstOnlyLinkedList::put(int pos, int value)
{
    Node* temp = first;
    int index = 0;

    while (temp != nullptr)
    {
        if (index == pos)
        {
            temp->data = value;
            return;
        }

        temp = temp->next;
        index++;
    }
}

void myFirstOnlyLinkedList::swap(int xi, int yi)
{
    if (xi == yi) return;

    Node* temp = first;
    Node* node1 = nullptr;
    Node* node2 = nullptr;

    int index = 0;

    while (temp != nullptr)
    {
        if (index == xi)
        {
            node1 = temp;
        }

        if (index == yi)
            node2 = temp;

        temp = temp->next;
        index++;
    }

    if (node1 && node2)
    {
        int t = node1->data;
        node1->data = node2->data;
        node2->data = t;
    }
}

void myFirstOnlyLinkedList::sort(bool asc)
{
    if (!first || !first->next) 
    {
        return;
    }

    for (Node* i = first; i != nullptr; i = i->next)
    {
        for (Node* j = i->next; j != nullptr; j = j->next)
        {
            if ((asc && i->data > j->data) || (!asc && i->data < j->data))
            {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
}


int main()
{

    myFirstOnlyLinkedList list;

    cout << "Insert values:\n";
    list.insertAtLast(10);
    list.insertAtLast(5);
    list.insertAtLast(20);
    list.insertAtLast(3);
    list.insertAtLast(7);

    list.display();

    cout << "\nSize: " << list.getSize() << endl;

    cout << "Value at position 2: " << list.get(2) << endl;

    cout << "\nUpdating position 2 to 99\n";
    list.put(2, 99);
    list.display();

    cout << "\nSwapping positions 1 and 3\n";
    list.swap(1, 3);
    list.display();

    cout << "\nSorting Ascending\n";
    list.sort(true);
    list.display();

    cout << "\nSorting Descending\n";
    list.sort(false);
    list.display();

    cout << "\nSearch 99: " << list.search(99) << endl;

    cout << "\nRemove First: " << list.removeFromFirst() << endl;
    list.display();

    cout << "Remove Last: " << list.removeFromLast() << endl;
    list.display();

    return 0;
}