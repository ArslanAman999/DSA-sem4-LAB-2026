#include<iostream>
using namespace std;
#include "Node.h"
// task1 A & B
template <typename T>
bool isBST(Node<T>* Parent, Node<T>* leftChild, Node<T>* rightChild)
{
    if (!Parent) return true;

    if (leftChild && leftChild->data >= Parent->data) return false;
    if (rightChild && rightChild->data <= Parent->data) return false;

    return true;
}

template <typename T>
bool isBST(Node<T>* Parent, Node<T>* leftChild, Node<T>* rightChild,
    Node<T>* leftChildLeft, Node<T>* leftChildRight,
    Node<T>* rightChildLeft, Node<T>* rightChildRight)
{
    if (!isBST(Parent, leftChild, rightChild)) return false;

    if (leftChild && leftChildLeft && leftChildLeft->data >= leftChild->data) return false;
    if (leftChild && leftChildRight && leftChildRight->data <= leftChild->data) return false;

    if (rightChild && rightChildLeft && rightChildLeft->data >= rightChild->data) return false;
    if (rightChild && rightChildRight && rightChildRight->data <= rightChild->data) return false;

    return true;
}

// task2 A & B
template <typename T>
bool isFound(T valueToFind, Node<T>* Parent, Node<T>* leftChild, Node<T>* rightChild) {
    if (!Parent) return false;
    if (Parent->data == valueToFind) return true;
    if (leftChild && leftChild->data == valueToFind) return true;
    if (rightChild && rightChild->data == valueToFind) return true;
    return false;
}

template <typename T>
bool isFound(T valueToFind, Node<T>* Parent, Node<T>* leftChild, Node<T>* rightChild,
    Node<T>* leftChildLeft, Node<T>* leftChildRight,
    Node<T>* rightChildLeft, Node<T>* rightChildRight) {
    return (Parent && Parent->data == valueToFind) ||
        (leftChild && leftChild->data == valueToFind) ||
        (rightChild && rightChild->data == valueToFind) ||
        (leftChildLeft && leftChildLeft->data == valueToFind) ||
        (leftChildRight && leftChildRight->data == valueToFind) ||
        (rightChildLeft && rightChildLeft->data == valueToFind) ||
        (rightChildRight && rightChildRight->data == valueToFind);
}

// task3 A & B

template <typename T>
void insertValue(T valueToInsert, Node<T>* Parent, Node<T>* leftChild, Node<T>* rightChild) {
    if (!Parent) return;

    if (valueToInsert < Parent->data && !leftChild) {
        Parent->left = new Node<T>(valueToInsert);
    }
    else if (valueToInsert > Parent->data && !rightChild) {
        Parent->right = new Node<T>(valueToInsert);
    }
}

template <typename T>
void insertValue(T valueToInsert, Node<T>* Parent, Node<T>* leftChild, Node<T>* rightChild,
    Node<T>* leftChildLeft, Node<T>* leftChildRight,
    Node<T>* rightChildLeft, Node<T>* rightChildRight) {
    if (!Parent) return;

    if (valueToInsert < Parent->data) {
        if (!leftChild) Parent->left = new Node<T>(valueToInsert);
        else if (valueToInsert < leftChild->data && !leftChildLeft) leftChild->left = new Node<T>(valueToInsert);
        else if (valueToInsert > leftChild->data && !leftChildRight) leftChild->right = new Node<T>(valueToInsert);
    }
    else {
        if (!rightChild) Parent->right = new Node<T>(valueToInsert);
        else if (valueToInsert < rightChild->data && !rightChildLeft) rightChild->left = new Node<T>(valueToInsert);
        else if (valueToInsert > rightChild->data && !rightChildRight) rightChild->right = new Node<T>(valueToInsert);
    }
}


// task4 A & B
template <typename T>
void deleteValue(T valueToDelete, Node<T>* Parent, Node<T>* leftChild, Node<T>* rightChild) {
    if (!Parent) return;

    if (leftChild && leftChild->data == valueToDelete) {
        delete leftChild;
        Parent->left = nullptr;
    }
    else if (rightChild && rightChild->data == valueToDelete) {
        delete rightChild;
        Parent->right = nullptr;
    }
    else if (Parent->data == valueToDelete) {
        // Special case: deleting root is tricky in fixed tree
        Parent->data = -1; // mark as deleted
    }
}


template <typename T>
void deleteValue(T valueToDelete, Node<T>* Parent, Node<T>* leftChild, Node<T>* rightChild,
    Node<T>* leftChildLeft, Node<T>* leftChildRight,
    Node<T>* rightChildLeft, Node<T>* rightChildRight) {
    if (!Parent) return;

    // Check root
    if (Parent->data == valueToDelete) {
        Parent->data = -1; // mark as deleted (special case)
        return;
    }

    // Check immediate children
    if (leftChild && leftChild->data == valueToDelete) 
    {
        delete leftChild;
        Parent->left = nullptr;
        return;
    }
    if (rightChild && rightChild->data == valueToDelete) 
    {
        delete rightChild;
        Parent->right = nullptr;
        return;
    }

    // Check grandchildren
    if (leftChildLeft && leftChildLeft->data == valueToDelete) {
        delete leftChildLeft;
        leftChild->left = nullptr;
        return;
    }
    if (leftChildRight && leftChildRight->data == valueToDelete) {
        delete leftChildRight;
        leftChild->right = nullptr;
        return;
    }
    if (rightChildLeft && rightChildLeft->data == valueToDelete) {
        delete rightChildLeft;
        rightChild->left = nullptr;
        return;
    }
    if (rightChildRight && rightChildRight->data == valueToDelete) {
        delete rightChildRight;
        rightChild->right = nullptr;
        return;
    }
}
// ------------------ Tester Main ------------------
int main() {

    Node<int>* Parent = new Node<int>(50);
    Node<int>* leftChild = new Node<int>(30);
    Node<int>* rightChild = new Node<int>(70);
    Parent->left = leftChild;
    Parent->right = rightChild;

    Node<int>* leftChildLeft = new Node<int>(20);
    Node<int>* leftChildRight = new Node<int>(40);
    leftChild->left = leftChildLeft;
    leftChild->right = leftChildRight;

    Node<int>* rightChildLeft = new Node<int>(60);
    Node<int>* rightChildRight = new Node<int>(80);
    rightChild->left = rightChildLeft;
    rightChild->right = rightChildRight;

    cout << "Is BST? " << isBST(Parent, leftChild, rightChild,
        leftChildLeft, leftChildRight,
        rightChildLeft, rightChildRight) << endl;

    cout << "Find 40? " << isFound(40, Parent, leftChild, rightChild,
        leftChildLeft, leftChildRight,
        rightChildLeft, rightChildRight) << endl;

    insertValue(25, Parent, leftChild, rightChild,
        leftChildLeft, leftChildRight,
        rightChildLeft, rightChildRight);
    cout << "Inserted 25 under leftChildLeft: "
        << (leftChildLeft->left ? leftChildLeft->left->data : -1) << endl;

    deleteValue(60, Parent, leftChild, rightChild,
        leftChildLeft, leftChildRight,
        rightChildLeft, rightChildRight);
    cout << "Deleted 60, rightChildLeft now: "
        << (rightChild->left ? rightChild->left->data : -1) << endl;

    return 0;
}

