/*
Reorder elements of stack using two extra stacks.
*/

#include <iostream>
#include "../4/stack.hpp"
#include "../swap.hpp"

using namespace std;

int main(void)
{
	cout << "Enter data size : " ;
	int size, temp;
	
	cin >> size;

	stack *a[3];

	a[0] = new stack(size);
	a[1] = new stack(size);
	a[2] = new stack(size);


	int array[size];

	cout << "Enter data elements  : ";

	for(int i = 0 ; i < size ; i ++ )
	{
		int temp1;
		cin >> temp1;
		a[0]->push(temp1);
	}

	cout << "Enter desired permuatation : ";
	for(int i = 0 ; i < size ; i ++ )
	{
		int temp2;
		cin >> temp2;
		array[i] = temp2;
	}

	int to_empty = 0, to_fill = 1;
	for(int i = 0 ; i < size ; i ++ )
	{
		while(!a[to_empty]->isEmpty())
		{
			a[to_empty]->pop(&temp);
			if(temp == array[size - 1 - i])
				a[2]->push(temp);
			else
				a[to_fill]->push(temp);
		}
		swap(&to_fill, &to_empty);
	}


	cout << "Final Rearrangement : \n";
	a[2]->display();

	return 0;
}