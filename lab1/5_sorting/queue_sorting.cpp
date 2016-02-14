/*
Sorting elements of queue using two extra queues.
*/

#include <iostream>
#include "../4/queue.hpp"
#include "../swap.hpp"

using namespace std;

int main(void)
{
	int size;
	cout << "Enter size : " ;
	cin >> size;

	queue *a[3];

	a[0] = new queue(size);
	a[1] = new queue(size);
	a[2] = new queue(size);

	cout << "Enter data : \n";
	for(int i = 0 ; i < size ; i ++ )
	{
		int temp;
		cin >> temp;
		a[0]->enqueue(temp);
	}

	int to_empty = 0, to_fill = 1;
	for(int i = 0 ; i < size ; i ++ )
	{
		int temp;
		while(!a[to_empty]->isEmpty())
		{
			if(a[to_fill]->peek(&temp))
			{
				int e;
				a[to_empty]->peek(&e);
				if(e < temp)
				{
					a[to_empty]->dequeue(&temp);
					a[to_fill]->enqueue(temp);
				}
				else
				{
					a[to_fill]->dequeue(&temp);
					a[to_empty]->enqueue(temp);
				}
			}
			else
			{
				a[to_empty]->dequeue(&temp);
				a[to_fill]->enqueue(temp);
			}
		}
		a[to_fill]->dequeue(&temp);
		a[2]->enqueue(temp);
		swap(&to_empty, &to_fill);
	}

	a[2]->display();

	return 0;
}