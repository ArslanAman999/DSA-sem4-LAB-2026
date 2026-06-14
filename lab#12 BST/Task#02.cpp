#include <iostream>
using namespace std;
#include"BinarySearchTree.h"

/*
For task number two, the BFS functions are implemented in
the exact same way as they were implemented for the global functions in task one, the only
difference being that instead of using iterative loop code, we used recursive functions.All the conditions, check conditions, base conditions,
loops are the exact same. Instead of using loops, helper functions are used to get the same behavior.
*/

int main()
{
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder: ";
    bst.inorderDisplay();
    cout << endl;

    cout << "Search 40: ";

    if (bst.search(40))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }

    cout << endl;

    bst.remove(70);

    cout << "After removing 70: ";

    cout << "inorder: ";
    bst.inorderDisplay();
    cout << endl;
    
    cout << "preorder: ";
    bst.preorderDisplay();
    cout << endl;
    
    cout << "postorder: ";
    bst.postorderDisplay();
    cout << endl;

    cout << "Height: "
        << bst.treeHeight()
        << endl;

    cout << "Node Count: "
        << bst.treeNodeCount()
        << endl;

    cout << "Leaves Count: " << bst.treeLeavesCount() << endl;

    return 0;
}
