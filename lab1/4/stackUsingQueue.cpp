/*
Implementation of stack using queue.
*/

#include "queue.hpp"

int main(void)
{
	int data, choice, size;

	cout << "Enter size : ";
	cin >> size;

	queue a(size);
	queue b(size);

	do
	{
		cin >> choice;

		if(choice == 1)
		{
			cout << "Enter data : " ;
			cin >> data;
			if(a.enqueue(data))
			{
				cout << "Pushed element.\n";
				a.display();
			}
			else
				cout << "Stack full.\n";
			
		}
		else if(choice == 2)
		{
			if(a.isEmpty())
			{
				cout << "Empty.\n";
				continue;
			}
			int temp;
			while(a.getFilled() > 1)
			{
				a.dequeue(&temp);
				b.enqueue(temp);
			}
			a.dequeue(&temp);
			cout << "Popped " << temp << endl;
			while(b.dequeue(&temp))
				a.enqueue(temp);
			a.display();
		}
		else if(choice == 0)
			return 0;
		else
			cout << "Invalid Input.\n";
	}while(true);

	return 0;
}