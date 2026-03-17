#pragma once
class Stack
{
protected:
	int currentIndex;
	int* values;
	int maxCapacity;

public:
	Stack(int _maxCapacity = 0)
	{
		currentIndex = -1;
		maxCapacity = _maxCapacity;
		values = new int[maxCapacity] {0};

	}
	Stack(const Stack& AA)
	{
		maxCapacity = AA.maxCapacity;
		values = new int[maxCapacity] {0};
	}
	virtual void push(int v) = 0; // increments currentIndex and add value if not full
	virtual bool pop(int& value) = 0; // if not empty returns the value at the currentIndex and decrementscurrentIndex
	bool isEmpty()
	{
		return (currentIndex < 0);
	}
	bool isFull()
	{
		return (currentIndex == maxCapacity - 1);
	}

};