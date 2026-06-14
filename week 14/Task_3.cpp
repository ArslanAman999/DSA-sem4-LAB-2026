#include <iostream>
#include <string>
using namespace std;
#include "AVLTree.h"
#include "MaxHeap.h"

/*
From the given question, I have created a struct named PairSTR, which has the following 
attributes: string ID and string password. We have a constructor, parameterized constructor,
then we have three functions, less than,
greater than, and equals to operation, if we want to perform on this struct type.

For search password, we check the root. First,
if the root is null PTR, we return an empty string. Then we check if the password
that we are searching for, if the ID provided is the same as the root ID, then we 
return the password. And if not, then we use another condition to
check if the ID that is provided is less than the
root's ID or greater than the root's ID. Depending upon that, we iterate to left or right.

To add new users, we use the add user function. For that, we
use the AVL's header file. It's the AVL insert function and insert th
e value inside it and store the returned root in the AVL root. Then, we insert the 
ID inside the heap and come out of the function. 

For removing a user, we use the AVL delete function
to first delete the value or the user that we want to delete. And then we
use the remove heap function to remove the ID from the heap. For display, we
simply display that I create the entire root by recalling the display function on the 
left root and the right root over and over again.
*/

struct PairStr
{
    string id;
    string pass;

    PairStr() : id(""), pass("") {}

    PairStr(string i, string p) : id(i), pass(p) {}

    bool operator<(const PairStr& o)  const 
    { 
        return id < o.id; 
    }
    bool operator>(const PairStr& o)  const 
    { 
        return id > o.id;
    }
    bool operator==(const PairStr& o) const 
    {
        return id == o.id;
    }
};


string searchPassword(Node<PairStr>* root, const string& uid) 
{
    if (root == nullptr) 
    {
        return "";
    }
    if (uid == root->data.id)
    {
        return root->data.pass;
    }
    if (uid < root->data.id)  
    {
        return searchPassword(root->left, uid);
    }
    return searchPassword(root->right, uid);
}


void printHeader() 
{
    cout << endl;
    cout << "|      User ID       |      Password      |\n";
    cout << endl;
}


void printRow(const string& id, const string& pass) 
{
    cout << "| " << id;

    for (int i = id.size(); i < 19; i++)
    {
        cout << " ";
    }
    cout << "| " << pass;

    for (int i = pass.size(); i < 19; i++)
    {
        cout << " ";
    }
    cout << "|\n";
}


void displayTable(Node<PairStr>* root) 
{
    if (root == nullptr)
    {
        return;
    }
    displayTable(root->left);
    printRow(root->data.id, root->data.pass);
    displayTable(root->right);
}


void addUser(Node<PairStr>*& avlRoot, MaxHeap<string>& idHeap,const string& uid, const string& pwd)
{
    avlRoot = insert(avlRoot, PairStr(uid, pwd));
    idHeap.insert(uid);
    cout << "User '" << uid << "' added.\n";
}


void removeUser(Node<PairStr>*& avlRoot, MaxHeap<string>& idHeap, const string& uid)
{
    avlRoot = avlDelete(avlRoot, PairStr(uid, ""));
    idHeap.remove(uid);
    cout << "User '" << uid << "' removed.\n";
}


void printMenu()
{
    cout << "\n=== User ID-Password System ===\n";
    cout << "a. Add user\n";
    cout << "b. Remove user\n";
    cout << "c. Search password\n";
    cout << "d. Display all users\n";
    cout << "q. Quit\n";
    cout << "Choice: ";
}

int main() 
{
    Node<PairStr>* passTree = nullptr;
    MaxHeap<string> idHeap;


    addUser(passTree, idHeap, "user123",  "pass123");
    addUser(passTree, idHeap, "user456",  "secretABC");
    addUser(passTree, idHeap, "user001",  "alpha999");
    addUser(passTree, idHeap, "admin",    "adminPass");

    char choice;
    do {
        printMenu();
        cin >> choice;

        if (choice == 'a')
        {
            string uid, pwd;
            cout << "Enter user ID: ";   cin >> uid;
            cout << "Enter password: ";  cin >> pwd;
            addUser(passTree, idHeap, uid, pwd);

        } 
        else if (choice == 'b') 
        {
            string uid;
            cout << "Enter user ID to remove: "; cin >> uid;
            removeUser(passTree, idHeap, uid);

        } 
        else if (choice == 'c')
        {
            string uid;
            cout << "Enter user ID to search: "; cin >> uid;
            string found = searchPassword(passTree, uid);
            if (found.empty())
            {
                cout << "User not found.\n";
            }
            else
            {
                cout << "Password for '" << uid << "': " << found << "\n";
            }

        } 
        else if (choice == 'd')
        {
            printHeader();
            displayTable(passTree);


        } 
        else if (choice != 'q')
        {
            cout << "Invalid option.\n";
        }

    } while (choice != 'q');

    cout << "Goodbye.\n";
    return 0;
}
