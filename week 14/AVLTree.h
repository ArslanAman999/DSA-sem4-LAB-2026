#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T val) : data(val), left(nullptr), right(nullptr) {}
};

template <class T>
int height(Node<T>* root) 
{
    if (root == nullptr) 
    {
        return -1;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + (lh > rh ? lh : rh);
}

template <class T>
int balance(Node<T>* root) 
{
    if (root == nullptr) 
    {
        return 0;
    }
    return height(root->left) - height(root->right);
}


template <class T>
int balanceType(Node<T>* parent, T newValue) 
{
    int bf = balance(parent);
    if (bf >= -1 && bf <= 1) 
    {
        return 0;
    }


    if (bf > 1)
    {

        if (newValue < parent->left->data) 
        {
            return 1;
        }
        else                              
        {
            return 3;
        }
    } 
    else 
    {

        if (newValue > parent->right->data)
        {
            return 2;
        }

        else                    
        {
            return 4;
        }

    }
}

template <class T>
Node<T>* leftRotate(Node<T>* root)
{
    Node<T>* newRoot = root->right;
    root->right      = newRoot->left;
    newRoot->left    = root;
    return newRoot;
}


template <class T>
Node<T>* rightRotate(Node<T>* root)
{
    Node<T>* newRoot = root->left;
    root->left       = newRoot->right;
    newRoot->right   = root;
    return newRoot;
}


template <class T>
Node<T>* bstInsert(Node<T>* root, T value) 
{
    if (root == nullptr) 
    {
        return new Node<T>(value);
    }
    if (value < root->data)
    {
        root->left = bstInsert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = bstInsert(root->right, value);
    }
    return root;
}


template <class T>
Node<T>* rebalance(Node<T>* root, T value) 
{
    int bf = balance(root);


    if (bf > 1 && value < root->left->data)
    {
        return rightRotate(root);
    }

    if (bf < -1 && value > root->right->data)
    {
        return leftRotate(root);
    }

    if (bf > 1 && value > root->left->data) 
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && value < root->right->data) 
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}


template <class T>
Node<T>* insert(Node<T>* root, T value) 
{
    root = bstInsert(root, value);
    return rebalance(root, value);
}


template <class T>
Node<T>* minNode(Node<T>* root)
{
    while (root->left != nullptr) root = root->left;
    {
        return root;
    }
}


template <class T>
Node<T>* bstDelete(Node<T>* root, T value) 
{
    if (root == nullptr) 
    {
        return nullptr;
    }

    if (value < root->data) 
    {
        root->left  = bstDelete(root->left,  value);
    }
    else if (value > root->data)
    {
        root->right = bstDelete(root->right, value);
    } 
    else 
    {

        if (root->left == nullptr) 
        {
            Node<T>* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) 
        {
            Node<T>* temp = root->left;
            delete root;
            return temp;
        }

        Node<T>* successor = minNode(root->right);
        root->data  = successor->data;
        root->right = bstDelete(root->right, successor->data);
    }
    return root;
}


template <class T>
Node<T>* avlDelete(Node<T>* root, T value) {
    root = bstDelete(root, value);
    if (root == nullptr) return nullptr;

    int bf = balance(root);


    if (bf > 1 && balance(root->left) >= 0)
        return rightRotate(root);

    if (bf > 1 && balance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && balance(root->right) <= 0)
        return leftRotate(root);

    if (bf < -1 && balance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}


template <class T>
void inorder(Node<T>* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
