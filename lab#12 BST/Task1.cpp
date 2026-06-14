#include <iostream>
using namespace std;
#include"BinarySearchTree.h"

/*
So for the search function, we store the root in a pointer, current, then we
traverse it. First, we check if the root isn't null. The loop starts and runs
until the root becomes null PTR. Then we check the condition. If the data inside
that root is equal to the value that we are searching, then we return
true. If not, then we check if the value inside that root is greater 
than or less than the value that we are trying to search. If it is less,
we change the address to the left child, and if it is not, then we change the address to the right child. 
This continues until the root becomes empty. In the case that no node is found, when the root becomes nullptr,
we get out of the while loop and return false.
*/
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

/*
For the add value function, we first create a new node storing the value that we want to
add. Then we check if the root node that is provided in the parameter is equals to null PTR. If it is,
then we just simply equate the root to the new node that we made and return. In the case that there 
are a value in the root, then we change it. We use two variables, current and parent.
We traverse through the BST until we find an empty spot. In the case that we find 
the same value, we return the function, deleting the node because BST doesn't have any 
unit value. In case of moving left or right, we use the same condition as above. If
it is smaller, we change the current variable to the left and otherwise we'll turn 
it to the right. Let's say that we found an empty spot. We come out of the while loop.
Then an if condition is checked. If the value is smaller, we insert it to the left. 
If it is greater, we insert it to the right and the function ends.
*/

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

/*
Find function. For the find function, we'll do the exact same thing as the search function. We'll traverse it in the
exact same way, but instead of returning a boolean value, we'll just simply return the current variable's  pointer.
*/
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
/*
To find the next largest value, we do the following. Firstly, we enter a loop until the node becomes null PTR. Then we 
check the condition if the data of the current node is greater than the value. If not, then
we move right because the right values are always greater in BST. Let's say the data
is greater than the value. Then we move left, saving the position of the node
that had the greater value. And then the loop repeats and we'll check the data again. This happens until the next largest value
is found because every value to the left of the greater value is going to be the smaller than the greater value.
*/

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

/*
Okay, so to delete a node, we will do the following. First, we have to check if the node exists, and if it exists, we 
have to store it in a variable named current. We use the parent in current node to traverse through 
the binary search tree, checking if we can find the value. If the value isn't found, the if condition current 
equals to null PTR returns the function. If it is found, this if condition doesn't run. Then we move on to the
cases that could be that either that parent or that node that we want to delete has either the 
left child or the right child. So we use an if condition and deduce that we store it in a variable and then we
delete that variable. The third case is that if that value has both the left or right value, meaning
it has both left child and right child. So we traverse from that node to its left child until we reach null PTR, storing
the value above the null PTR. Then when the null PTR is found, we came out of the while loop and then we store the value of that node
inside the node that we want to delete, meaning we overwrite the data. Then we use simple if-else statement to change 
the value of the successor parent's left and successor parent's right.
*/

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
