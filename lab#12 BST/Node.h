#pragma once
template <class T>
class Node
{
 public:
    T data;
    Node* left; // left child
    Node* right; // right child

    Node(const T& value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
