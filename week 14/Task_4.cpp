#include <iostream>
#include <string>
using namespace std;

/*
 for getIndex getLinearKey getQuardKey   getCode getHashCode  just applied the formulas

 For insertion, we use the getQuadKey function to get the index in which the data
 should be inserted. If that index is empty, we insert the value. If it is not, 
 then we recall the index function, increasing the offset by 1.

 For retrieving, we just simply calculate the getQuadKey and return the value in its index.

 For inserting a key, we use the getHashCode function, applying it to the 
 formula, and the index we get, we insert it in that if that index is empty. If 
 it is not empty, then we recall the insert function but increase the offset by 1. 
 
 Retrieve does the exact same thing, just apply the formula, offset
 modulus size, and retrieve the value in that index.
*/
const int OFFSET = 7; 

int getIndex(int value, int size) 
{
    return value % size;
}

int getLinearKey(int value, int size, int offset) 
{
    return getIndex(value + offset, size);
}

int getQuardKey(int value, int size, int offset) 
{
    return (getIndex(value, size) + offset * offset) % size;
}

int getCode(int value, int size, int offset) 
{
    return (getIndex(value, size) + offset * getQuardKey(value, size, OFFSET)) % size;
}

int getHashCode(const char* str) 
{
    int sum = 0;
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) 
    { 
        sum += str[i]; len++;
    }
    if (len == 0) 
    {
        return 0;
    }
    return sum % len;
}

void insert(int* a, int size, int offset, int value) 
{
    int idx = getQuardKey(value, size, offset);

    if (a[idx] == -1) 
    {
        a[idx] = value;
    } 
    else
    {
        insert(a, size, offset + 1, value); 
    }
}


int retrieve(int* a, int size, int offset)
{
    return a[getQuardKey(0, size, offset)];
}


void insert(string* a, int size, int offset, string str) 
{
    int idx = (getHashCode(str.c_str()) + offset) % size;
    if (a[idx].empty()) 
    {
        a[idx] = str;
    } 
    else
    {
        insert(a, size, offset + 1, str); 
    }
}


string retrieve(string* a, int size, int offset)
{
    int idx = offset % size;
    return a[idx];
}


void printIntArray(int* a, int size)
{
    for (int i = 0; i < size; i++) 
    {
        cout << "[" << i << "] = ";
        if (a[i] == -1) 
        {
            cout << "(empty)";
        }
        else 
        {
            cout << a[i];
        }
        cout << "\n";
    }
}


void printStrArray(string* a, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << "[" << i << "] = ";
        if (a[i].empty())
        {
            cout << "(empty)";
        }
        else 
        {
            cout << a[i];
        }
        cout << "\n";
    }
}

int main() 
{
    const int SZ = 10;


    cout << "=== Hash Function Tests ===\n";
    cout << "getIndex(23, 10)         = " << getIndex(23, 10) << "\n";
    cout << "getLinearKey(23,10,2)    = " << getLinearKey(23, 10, 2) << "\n";
    cout << "getQuardKey(23,10,2)     = " << getQuardKey(23, 10, 2) << "\n";
    cout << "getCode(23,10,1)         = " << getCode(23, 10, 1) << "\n";
    cout << "getHashCode(\"hello\")     = " << getHashCode("hello") << "\n";


    cout << "\n=== Integer Hash Table ===\n";
    int iTable[SZ];
    for (int i = 0; i < SZ; i++) iTable[i] = -1; 
    insert(iTable, SZ, 0, 23);
    insert(iTable, SZ, 0, 33);
    insert(iTable, SZ, 0, 43);
    insert(iTable, SZ, 0, 7);
    printIntArray(iTable, SZ);


    cout << "\n=== String Hash Table ===\n";
    string sTable[SZ];
    insert(sTable, SZ, 0, "apple");
    insert(sTable, SZ, 0, "banana");
    insert(sTable, SZ, 0, "cherry");
    insert(sTable, SZ, 0, "hi");
    insert(sTable, SZ, 0, "go");
    printStrArray(sTable, SZ);

    cout << "\nRetrieve index 0: " << retrieve(sTable, SZ, 0) << "\n";

    return 0;
}
