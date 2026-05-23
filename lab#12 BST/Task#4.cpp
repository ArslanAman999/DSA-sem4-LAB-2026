#include <iostream>
using namespace std;
#include <fstream>
#include <string>
//#include <cctype>
#include"BinarySearchTree.h"


int main()
{
    BinarySearchTree<string> tree;

    ifstream fin("para.txt");

    if (!fin)
    {
        cout << "File not found" << endl;
        return 0;
    }

    string word;

    // Task 1
    while (fin >> word)
    {
        tree.insert(word);
    }

    fin.close();

    // Task 2
    cout << "Words stored in tree:" << endl;

    tree.inorderDisplay();

    cout << endl << endl;

    // Task 3
    string searchWord;

    cout << "Enter word to search and convert to uppercase: ";
    cin >> searchWord;

    Node<string>* found = tree.findNode(searchWord);

    if (found != nullptr)
    {
        for (int i = 0; i < found->data.length(); i++)
        {
            found->data[i] = toupper(found->data[i]);
        }

        cout << "Word converted to uppercase." << endl;
    }
    else
    {
        cout << "Word not found." << endl;
    }

    cout << endl;

    tree.inorderDisplay();

    cout << endl << endl;

    // Task 4
    string insertWord;

    cout << "Enter word to insert: ";
    cin >> insertWord;

    tree.insert(insertWord);

    cout << "Tree after insertion:" << endl;

    tree.inorderDisplay();

    cout << endl << endl;

    // Task 5
    string deleteWord;

    cout << "Enter word to delete: ";
    cin >> deleteWord;

    tree.remove(deleteWord);

    cout << "Tree after deletion:" << endl;

    tree.inorderDisplay();

    cout << endl;

    return 0;
}