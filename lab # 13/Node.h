#pragma once
#include <iostream>

template <class T>
class Node
{
 public:
    T data;
    Node* left; // left child
    Node* right; // right child
    Node(T val) : data(val), left(nullptr), right(nullptr) {}
};
