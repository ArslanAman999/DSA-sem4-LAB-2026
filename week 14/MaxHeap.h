#pragma once
#include <iostream>
using namespace std;

template <class T>
class MaxHeap {
public:
    MaxHeap();
    MaxHeap(const MaxHeap<T>& mh);
    const MaxHeap<T>& operator=(const MaxHeap<T>& mh);
    ~MaxHeap();

    void insert(const T& value);
    void remove(const T& value);
    bool search(const T& value) const;
    void heapsort();
    bool isEmpty() const;
    bool isFull()  const;
    void inorderDisplay() const;

protected:
    T*   array;
    int  capacity;
    int  size;

    void maxHeapify(int i);
    void buildHeap();

private:

    int parent(int i) const 
    {
        return (i - 1) / 2; 
    }
    int leftChild(int i)  const 
    { 
        return 2 * i + 1;
    }
    int rightChild(int i) const 
    {
        return 2 * i + 2;
    }

    void swap(int a, int b) 
    {
        T tmp = array[a];
        array[a] = array[b];
        array[b] = tmp;
    }

    void copyFrom(const MaxHeap<T>& mh);
    void inorderHelper(int i) const;
};


template <class T>
MaxHeap<T>::MaxHeap() : capacity(100), size(0) 
{
    array = new T[capacity];
}


template <class T>
MaxHeap<T>::MaxHeap(const MaxHeap<T>& mh) 
{
    capacity = mh.capacity;
    size     = mh.size;
    array    = new T[capacity];
    for (int i = 0; i < size; i++) 
    {
        array[i] = mh.array[i];
    }
}

template <class T>
const MaxHeap<T>& MaxHeap<T>::operator=(const MaxHeap<T>& mh)
{
    if (this == &mh)
    {
        return *this;
    }
    delete[] array;
    capacity = mh.capacity;
    size     = mh.size;
    array    = new T[capacity];
    for (int i = 0; i < size; i++) 
    {
        array[i] = mh.array[i];
    }
    return *this;
}

template <class T>
MaxHeap<T>::~MaxHeap() 
{
    delete[] array;
}


template <class T>
bool MaxHeap<T>::isEmpty() const
{
    return size == 0; 
}

template <class T>
bool MaxHeap<T>::isFull() const  
{ 
    return size == capacity;
}


template <class T>
void MaxHeap<T>::maxHeapify(int i)
{
    int largest = i;
    int l = leftChild(i);
    int r = rightChild(i);
    if (l < size && array[l] > array[largest])
    {
        largest = l;
    }
    if (r < size && array[r] > array[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(i, largest);
        maxHeapify(largest);
    }
}


template <class T>
void MaxHeap<T>::buildHeap() 
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        maxHeapify(i);
    }
}


template <class T>
void MaxHeap<T>::insert(const T& value) {
    if (isFull()) 
    {
        cout << "Heap is full!\n"; 
        return; 
    }
    array[size] = value;
    int i = size++;

    while (i > 0 && array[parent(i)] < array[i])
    {
        swap(i, parent(i));
        i = parent(i);
    }
}


template <class T>
bool MaxHeap<T>::search(const T& value) const
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            return true;
        }
    }
    return false;
}


template <class T>
void MaxHeap<T>::remove(const T& value) 
{
    int idx = -1;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << "Value not found\n";
        return;
    }
    array[idx] = array[--size];
    buildHeap();
}


template <class T>
void MaxHeap<T>::heapsort() 
{
    int origSize = size;
    buildHeap();
    for (int i = size - 1; i > 0; i--) 
    {
        swap(0, i);
        size--;
        maxHeapify(0);
    }
    size = origSize;
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) 
    {
        cout << array[i] << " ";
    }
    cout << "\n";
    buildHeap(); 
}


template <class T>
void MaxHeap<T>::inorderHelper(int i) const
{
    if (i >= size) 
    {
        return;
    }
    inorderHelper(leftChild(i));
    cout << array[i] << " ";
    inorderHelper(rightChild(i));
}

template <class T>
void MaxHeap<T>::inorderDisplay() const 
{
    inorderHelper(0);
    cout << "\n";
}