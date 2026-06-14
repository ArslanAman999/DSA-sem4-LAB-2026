#include <iostream>
#include "MaxHeap.h"
using namespace std;
/*
The parent function calculate and returns the index of the parent note the left child and the 
right child do the same. The return the index value of the left challenge in the right child
swap function swap the value of two given index then there is that is empty and is full function?

Maxheapify
Heap is an index as a parameter and check if that index is 
child, follow the DST rules. In case the left or the right
child do not follow the rule, we use the swap function and then use recall 
the heapify function on the swapped index to check the further childs.

The build heap function just cause the max heapigy function in reverse order from the middle of the array

For insert function, first we check if the array is full. If
it is full, we cannot add value. Otherwise, we
add the value at the very last index. Then 
we compare the value with parent. If the value that we added is greater than that
of the parent, we swap the value with the parent.

for search we use linear search

For remove we use the linear search approach
to find and store the index of the value that we want to date if
the value isn’t found we returned and if it is found we swept that index is value with that
of the last and then we decrease the size by one at the 
end we call the built heap function to arrange the array
*/
int main() {
    MaxHeap<int> h;


    cout << "=== Inserting: 50 30 40 10 20 60 ===\n";
    h.insert(50); h.insert(30); h.insert(40);
    h.insert(10); h.insert(20); h.insert(60);

    cout << "Inorder display: ";
    h.inorderDisplay();


    cout << "Search 40: " << (h.search(40) ? "Found" : "Not found") << "\n";
    cout << "Search 99: " << (h.search(99) ? "Found" : "Not found") << "\n";


    cout << "\n=== Removing 40 ===\n";
    h.remove(40);
    cout << "Inorder display: ";
    h.inorderDisplay();


    cout << "\n=== Heapsort ===\n";
    h.heapsort();


    MaxHeap<int> h2(h);
    cout << "\n=== Copy of heap inorder: ";
    h2.inorderDisplay();


    MaxHeap<int> h3;
    h3 = h;
    cout << "=== Assigned heap inorder: ";
    h3.inorderDisplay();

    cout << "\nisFull: " << (h.isFull() ? "yes" : "no") << "\n";
    cout << "isEmpty: " << (h.isEmpty() ? "yes" : "no") << "\n";

    return 0;
}
