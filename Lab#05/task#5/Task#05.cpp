#include <iostream>
using namespace std;

/*
display():
Traverses the list from first node to last node and prints each value.

removeFromFirst():
Removes the first node and returns its value.
Updates first pointer to next node.

removeFromLast():
Traverses to the last node then we removes it.

insertSorted(int):
we first Traverses to that specifice value then assigne the addres of the new to to the pos-1 node and this 
nodes next = pos+1 address


deleteValue(int):
we seach for the value by Traversing then remove it my assigning the address 
of the pervous not to that of the next 


search(int):
we Traverse until the end if found return trueother wose false

isEmpty():
Returns true if first pointer is null.
*/
void SortedFirstOnlyLinkedList::display()
{
    Node* temp = first;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int SortedFirstOnlyLinkedList::removeFromFirst()
{
    if (first == nullptr) 
    {
        return -1;
    }

    Node* temp = first;
    int val = temp->data;

    first = first->next;
    delete temp;
    return val;
}


int SortedFirstOnlyLinkedList::removeFromLast()
{
    if (first == nullptr) return -1;

    if (first->next == nullptr)
    {
        int val = first->data;
        delete first;
        first = nullptr;
        return val;
    }

    Node* temp = first;

    while (temp->next->next != nullptr)
        temp = temp->next;

    int val = temp->next->data;
    delete temp->next;
    temp->next = nullptr;

    return val;
}

void SortedFirstOnlyLinkedList::insertSorted(int value)
{
    if (!first || value < first->data)
    {
        insertAtFirst(value);
        return;
    }

    Node* temp = first;

    while (temp->next != nullptr && temp->next->data < value)
        temp = temp->next;

    if (temp->next == nullptr)
    {
        insertAtLast(value);
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

bool SortedFirstOnlyLinkedList::deleteValue(int value)
{
    if (!first) 
    {
        return false;
    }

    if (first->data == value)
    {
        removeFromFirst();
        return true;
    }

    Node* temp = first;

    while (temp->next != nullptr && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        return false;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;

    return true;
}

bool SortedFirstOnlyLinkedList::search(int value)
{
    Node* temp = first;

    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

bool SortedFirstOnlyLinkedList::isEmpty()
{
    return first == nullptr;
}