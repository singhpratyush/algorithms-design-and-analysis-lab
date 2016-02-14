/*
Class for stack with integer type data.
*/

#include <iostream>
#include <malloc.h>

using namespace std;

class stack
{
	int size;
	int *array;
	int top;

public:

	stack()
	{
		stack(10);
	}	

	stack(int a)
	{
		size = a;
		array = (int*)calloc(size,sizeof(int));
		top = -1;
	}

	bool push(int data)
	{
		if(top == size - 1)
			return false;
		array[++top] = data;
		return true;
	}

	bool pop(int *data)
	{
		if(top == -1)
		{
			*data = 0;
			return false;
		}
		*data = array[top--];
		return true;
	}

	int getFilled()
	{
		return top+1;
	}

	void display()
	{
		if(!isEmpty())
		{
			for(int i = 0 ; i <= top ; i ++ )
				cout << array[i] << " ";
		}
		cout << "\n\n";
	}

	bool isEmpty()
	{
		if(top == -1)
			return true;
		return false;
	}

	bool isFull()
	{
		if(top == -1)
			return true;
		return false;
	}

};