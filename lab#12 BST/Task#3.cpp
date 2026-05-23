#include <iostream>
using namespace std;
#include"BinarySearchTree.h"

template <class T>
void split(BinarySearchTree<T>& bt, BinarySearchTree<T>& btLeft, BinarySearchTree<T>& btRight)
{
    Node<T>* root = bt.getRoot();

    if (root == nullptr)
    {
        return;
    }

    btLeft.setRoot(root->left);

    btRight.setRoot(root->right);

    root->left = nullptr;
    root->right = nullptr;
}

//////////
template <class T>
void insertNodes(BinarySearchTree<T>& bt, Node<T>* node)
{
    if (node == nullptr)
    {
        return;
    }

    bt.insert(node->data);

    insertNodes(bt, node->left);

    insertNodes(bt, node->right);
}

template <class T>
void insert(BinarySearchTree<T>& bt,BinarySearchTree<T> toInsert)
{

    insertNodes(bt, toInsert.getRoot());
}

///////////


template <class T>
void deleteSubtree(Node<T>*& node)
{
    if (node == nullptr)
    {
        return;
    }

    deleteSubtree(node->left);

    deleteSubtree(node->right);

    delete node;

    node = nullptr;
}

template <class T>
void deleteTreeFromNode(BinarySearchTree<T>& bt,const T& value)
{
    Node<T>* current = bt.getRoot();
    Node<T>* parent = nullptr;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            break;
        }

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

    // deleting root subtree
    if (parent == nullptr)
    {
        deleteSubtree(current);

        bt.setRoot(nullptr);

        return;
    }

    if (parent->left == current)
    {
        parent->left = nullptr;
    }
    else
    {
        parent->right = nullptr;
    }

    deleteSubtree(current);
}

#include <iostream>
using namespace std;

int main()
{
    BinarySearchTree<int> bt;

    bt.insert(50);
    bt.insert(30);
    bt.insert(70);
    bt.insert(20);
    bt.insert(40);
    bt.insert(60);
    bt.insert(80);

    cout << "Original Tree: ";
    bt.inorderDisplay();
    cout << endl;

   BinarySearchTree<int> leftTree;
   BinarySearchTree<int> rightTree;

    split(bt, leftTree, rightTree);

    cout << "Left Tree: ";
    leftTree.inorderDisplay();
    cout << endl;

    cout << "Right Tree: ";
    rightTree.inorderDisplay();
    cout << endl;

    BinarySearchTree<int> another;

    another.insert(100);
    another.insert(90);
    another.insert(110);

    insert(leftTree, another);

    cout << "After inserting another tree: ";
    leftTree.inorderDisplay();
    cout << endl;

    deleteTreeFromNode(leftTree, 100);

    cout << "After deleting subtree from 100: ";
    leftTree.inorderDisplay();
    cout << endl;

    return 0;
}