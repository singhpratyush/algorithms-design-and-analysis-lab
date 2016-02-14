/*
Implementation of hashing using probing.
*/

#include "probing.hpp"

using namespace std;

int main(void)
{
	cout << "Enter Size : ";
	int size;

	cin >> size;

	probing hasher(size);

	int choice, temp1, temp2;

	do
	{
		cout << "0. Exit\n1. Insert\n2. Delete\n3. Display\n\tEnter Your Choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Enter <key> <data> : ";
				cin >> temp1 >> temp2;
				if(hasher.insert_element(temp1,temp2))
					cout << "Success." << endl;
				else
					cout << "Failed." << endl;
				break;

			case 2:
				cout << "Enter <key> : " ;
				cin >> temp1;
				if(hasher.delete_element(temp1))
					cout << "Success.\n";
				else
					cout << "Failed.\n";
				break;

			case 3:
				hasher.display();
		}
	}while(choice != 0);

	return 0;
}