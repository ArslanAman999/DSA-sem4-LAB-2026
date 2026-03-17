#include "Stack.h"
#pragma once
class MyStack : public Stack
{
public:
	MyStack(int CI = 0) : Stack(CI) {};
	MyStack(const MyStack& ma) : Stack(ma) {};
	void push(int v)
	{
		if (!isFull())
		{
			values[++currentIndex] = v;
			return;
		}
		//cout << "Array is full\n";
	}
	bool pop(int& v)
	{
		if (!isEmpty())
		{
			v = values[currentIndex--];
			return true;
		}
		return false;
	}
};

