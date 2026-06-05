#pragma once
#include <iostream>

template <class T>
class PriorityQueue: public ArrayQueue<T>
{
public:
  // Constructors
  PriorityQueue(int s);
  // Destructor
  ~PriorityQueue();
  // enqueue based on priority
  void enqueue(int priority, T value) ;
  T dequeue() ; // remove the value with the highest priority
    // Display the queue priority and values
  void display() ;
private:
  int* priorities;
  void maxHeapify(int i);
  void buildMaxHeap();
};

