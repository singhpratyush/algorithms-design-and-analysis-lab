/*
Reorder elements of queue using two extra queues.
*/

#include <iostream>
#include "../4/queue.hpp"
#include "../swap.hpp"

using namespace std;

int main(void)
{
	cout << "Enter data size : " ;
	int size, temp;
	
	cin >> size;

	queue a[3](size);

	int array[size];

	cout << "Enter data elements  : ";

	for(int i = 0 ; i < size ; i ++ )
	{
		int temp1;
		cin >> temp1;
		a[0].enqueue(temp1);
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
		while(!a[to_empty].isEmpty())
		{
			a[to_empty].dequeue(&temp);
			if(temp == array[size - 1 - i])
				a[2].enqueue(temp);
			else
				a[to_fill].enqueue(temp);
		}
		swap(&to_empty, &to_fill);
	}

	cout << "Final Rearrangement : \n";
	a[2].display();

	return 0;
}