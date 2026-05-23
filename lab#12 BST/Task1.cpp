#include <iostream>
using namespace std;
#include"BinarySearchTree.h"

template <class T>
bool search(Node<T>* root, T value)
{
    Node<T>* current = root;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true;
        }

        if (value < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    return false;
}

template <class T>
void addValue(Node<T>*& root, T value)
{
    Node<T>* newNode = new Node<T>(value);

    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    Node<T>* current = root;
    Node<T>* parent = nullptr;

    while (current != nullptr)
    {
        parent = current;

        if (value < current->data)
        {
            current = current->left;
        }
        else if (value > current->data)
        {
            current = current->right;
        }
        else
        {
            delete newNode;
            return;
        }
    }

    if (value < parent->data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
}

template <class T>
Node<T>* find(Node<T>* root, T value)
{
    Node<T>* current = root;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return current;
        }

        if (value < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    return nullptr;
}

template <class T>
Node<T>* findNextLarger(Node<T>* root, T value)
{
    Node<T>* current = root;
    Node<T>* successor = nullptr;

    while (current != nullptr)
    {
        if (current->data > value)
        {
            successor = current;
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    return successor;
}

template <class T>
void deleteNode(Node<T>*& root, T value)
{
    Node<T>* parent = nullptr;
    Node<T>* current = root;

    while (current != nullptr && current->data != value)
    {
        parent = current;

        if (value < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (current == nullptr)
    {
        return;
    }

    // Case 1 and 2
    if (current->left == nullptr || current->right == nullptr)
    {
        Node<T>* child;

        if (current->left != nullptr)
        {
            child = current->left;
        }
        else
        {
            child = current->right;
        }

        if (parent == nullptr)
        {
            root = child;
        }
        else if (parent->left == current)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }

        delete current;
    }

    // Case 3
    else
    {
        Node<T>* successorParent = current;
        Node<T>* successor = current->right;

        while (successor->left != nullptr)
        {
            successorParent = successor;
            successor = successor->left;
        }

        current->data = successor->data;

        if (successorParent->left == successor)
        {
            successorParent->left = successor->right;
        }
        else
        {
            successorParent->right = successor->right;
        }

        delete successor;
    }
}

#include <iostream>
using namespace std;

int main()
{
    Node<int>* root = nullptr;

    addValue(root, 50);
    addValue(root, 30);
    addValue(root, 70);
    addValue(root, 20);
    addValue(root, 40);
    addValue(root, 60);
    addValue(root, 80);

    cout << "Search 40: ";

    if (search(root, 40))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }

    cout << endl;

    Node<int>* found = find(root, 60);

    if (found != nullptr)
    {
        cout << "Find 60: " << found->data << endl;
    }

    Node<int>* next = findNextLarger(root, 65);

    if (next != nullptr)
    {
        cout << "Next Larger than 65: "
            << next->data
            << endl;
    }

    deleteNode(root, 70);

    cout << "Deleted 70" << endl;

    return 0;
}