/*
Implementation of queue using stack.
*/

#include "stack.hpp"

using namespace std;

int main(void)
{
	int data, choice, size;

	cout << "Enter size : ";
	cin >> size;

	stack a(size);
	stack b(size);

	do
	{
		cout << "0. Exit\n1. Enqueue\n2. Dequeue\n";
		cin >> choice;

		if(choice == 1)
		{
			cout << "Enter data : " ;
			cin >> data;
			if(!a.push(data))
				cout << "Queue full.\n";
			else
				cout << "Done.\n";
			a.display();
		}
		else if(choice == 2)
		{
			int temp;
			while(a.getFilled() > 1)
			{
				a.pop(&temp);
				b.push(temp);
			}
			a.pop(&temp);
			while(b.pop(&temp))
				a.push(temp);
			a.display();
		}
		else if(choice == 0)
			return 0;
		else
			cout << "Invalid Input.\n";
	}while(true);

	return 0;
}