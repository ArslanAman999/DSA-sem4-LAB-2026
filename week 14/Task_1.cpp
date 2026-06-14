/*
 For the first height function, I will simply call the function again and again in recursive for the base 
 condition being when the root becomes null PTR, we return minus 1 and afterwards any returned
 is returned with the addition of plus 1. And the greater of left and right is always returned. 
 
 For function 2, balance, I simply calculated the BF factor by negating the height of left
 child with the right child
 
 function 3, balance type, we first use the balance function to get the balance factor. Then 
 we use the conditions. If it is greater than 1, we check if the value that
 we are checking is greater than the data value of the parent's left. If it is, then we
 return case 3 and if it is less than the parent's left data, we return 1. The same we do for the
 right side to get the case 2 and case 3. For the left 
 rotate function, we store the value of the child node
 into a new node. Then we save the address of the left of 
 the new node into the original root. And then we move the root to the left of the child's node. 
 For the right rotate, we do the exact same thing, but we save and swap the values of the left side. For 
 BST insert, we just insert the value. If it is less than root, it goes to the left. If it is greater than 
 the root, it goes to the right. This continues until a space is found. In case that same exact value is found, 
 we do not insert that value.

 For AVL insert, we call the binary search insert first, then we check the balance 
 factor. After checking the balance factor, we check if the tree is balanced or not. If it
 is not, then we find out the type of 
 imbalance. When we have the type of balance, we apply the correct rotation.

 For binary search deletion, we have three cases. Firstly, the node has no child,
 the node is a leaf node, so we delete it immediately with no repercussions. The 
 second case is that it has one child, so we store the value of the child into the root
 and delete the parent. In case there are two childs, both left and right, we find to the
 left the next minimum value. When we find it, we replace it with the value that we are going to delete, 
 and then we delete the original value. For this, we use the
 helper function min node. The min node root traverses 
 the entire left side of the parent and finds the next smallest value. Lastly, we have AVL deletion. 
 
 For AVL deletion, we first call the BST binary search tree deletion. 
 Then we calculate the balance factor. If it is imbalanced, we find out the type of imbalance 
 and then we apply the correct rotations.
 */

#include <iostream>
#include "AVLTree.h"
using namespace std;

int main() {
    Node<int>* root = nullptr;


    int vals[] = {10, 20, 30, 15, 25, 5, 35};
    cout << "=== Inserting: 10 20 30 15 25 5 35 ===\n";
    for (int v : vals)
        root = insert(root, v);

    cout << "Inorder (should be sorted): ";
    inorder(root);
    cout << "\n";

    cout << "Height of tree : " << height(root) << "\n";
    cout << "Balance factor : " << balance(root) << "\n";


    Node<int>* demo = nullptr;
    demo = bstInsert(demo, 10);
    demo = bstInsert(demo, 20);
    demo = bstInsert(demo, 30); 


    cout << "\nbalanceType(demo root=10, 30) = "<< balanceType(demo, 30)<< " (expect 2 = RR, BF=" << balance(demo) << ")\n";


    cout << "\n=== Deleting 20 ===\n";
    root = avlDelete(root, 20);
    cout << "Inorder after delete: ";
    inorder(root);
    cout << "\n";

    cout << "=== Deleting 10 ===\n";
    root = avlDelete(root, 10);
    cout << "Inorder after delete: ";
    inorder(root);
    cout << "\n";

    return 0;
}
