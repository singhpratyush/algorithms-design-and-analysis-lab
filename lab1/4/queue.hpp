/*
Class for queue with integer type data.
*/

#include <iostream>
#include <malloc.h>

using namespace std;

class queue
{
	int size;
	int *array;
	int head, tail, filled;

public:

	queue(int a)
	{
		size = a;
		array = (int*)calloc(size, sizeof(int));
		head = -1;
		tail = 0;
		filled = 0;
	}

	queue()
	{
		queue(10);
	}

	bool enqueue(int data)
	{
		if(size == filled)
			return false;
		head = (head+1)%size;
		array[head] = data;
		filled ++ ;
		return true;
	}

	bool dequeue(int *data)
	{
		if(filled == 0)
			return false;
		*data = array[tail];
		tail = (tail+1)%size;
		filled -- ;
		return true;
	}

	bool peek(int *a)
	{
		if(filled == 0)
			return false;
		*a = array[tail];
		return true;
	}

	bool isEmpty()
	{
		if(filled == 0)
			return true;
		return false;
	}

	bool isFull()
	{
		if(size == filled)
			return true;
		return false;
	}

	int getFilled()
	{
		return filled;
	}

	void display()
	{
		int count = 0, i = tail;
		while(count < filled)
		{
			cout << array[i] << endl;
			i = (i+1) % size;
			count ++ ;
		}
		cout << "\n\n";
	}

};