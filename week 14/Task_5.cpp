#include <iostream>
#include <string>
using namespace std;

#include "AVLTree.h"

/*
For the add function, we can calculate the hash code using the 
getHashCode function and finding its mode with size. Then we use that 
index and store the root of the BST insert in the array.


For the search, we calculate the code and then we use the 
BST search function. The BST search function just iterates through
the entire root finding the value. If it finds it, it returns it. If it doesn't find it, 
it returns false.

For the remove function, we first calculate
the code of the index. Then we search it. If it isn't found,
we return nothing. Then we call the BST delete function to delete the value and return the string.
*/
int getHashCode(const char* str)
{
    int sum = 0;
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        sum += str[i]; len++; 
    }
    if (len == 0)
    {
        return 0;
    }
    return sum % len;
}


bool bstSearch(Node<string>* root, const string& val)
{
    if (root == nullptr) 
    {
        return false;
    }
    if (root->data == val) 
    {
        return true;
    }
    if (val < root->data) 
    {
        return bstSearch(root->left, val);
    }
    return bstSearch(root->right, val);
}


void add(Node<string>** a, int size, string str)
{
    int idx = getHashCode(str.c_str()) % size;
    a[idx] = bstInsert(a[idx], str);
}


bool search(Node<string>** a, int size, string str)
{
    int idx = getHashCode(str.c_str()) % size;
    return bstSearch(a[idx], str);
}


string removeStr(Node<string>** a, int size, string str)
{
    int idx = getHashCode(str.c_str()) % size;
    if (!bstSearch(a[idx], str))
    {
        return "";
    }
    a[idx] = bstDelete(a[idx], str);
    return str;
}

void displaySlot(Node<string>* root)
{
    if (root == nullptr)
    {
        return;
    }
    displaySlot(root->left);
    cout << root->data << " ";
    displaySlot(root->right);
}


void displayTable(Node<string>** a, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << "Slot [" << i << "]: ";
        if (a[i] == nullptr) 
        {
            cout << "(empty)";
        }
        else displaySlot(a[i]);
        {
            cout << "\n";
        }
    }
}

int main() {
    const int SZ = 7;
    Node<string>* table[SZ];
    for (int i = 0; i < SZ; i++) 
    {
        table[i] = nullptr;
    }


    cout << "=== Adding: cat, bat, hat, rat, dog, log, fog ===\n";
    add(table, SZ, "cat");
    add(table, SZ, "bat");
    add(table, SZ, "hat");
    add(table, SZ, "rat");
    add(table, SZ, "dog");
    add(table, SZ, "log");
    add(table, SZ, "fog");

    cout << "\n--- Hash Table State ---\n";
    displayTable(table, SZ);


    cout << "\n=== Search ===\n";
    cout << "Search 'hat': " << (search(table, SZ, "hat") ? "Found" : "Not Found") << "\n";
    cout << "Search 'xyz': " << (search(table, SZ, "xyz") ? "Found" : "Not Found") << "\n";


    cout << "\n=== Removing 'bat' ===\n";
    string removed = removeStr(table, SZ, "bat");
    cout << "Removed: '" << removed << "'\n";

    cout << "\n--- Hash Table After Remove ---\n";
    displayTable(table, SZ);

    return 0;
}
