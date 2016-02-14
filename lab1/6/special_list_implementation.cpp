/*
Implementation of special list mentioned in question 6.
*/

#include "list_special.hpp"

using namespace std;

int main(void)
{
	int choice, temp;
	special_list list;
	do
	{
		cout << "\n1. Insert Data\n2. Delete Data\n3. Display List.\n\n\tEnter your choice : ";
		cin >> choice;

		switch(choice)
		{
			case 1:
				cout << "Enter data : " ;
				cin >> temp;
				if(list.insert_data(temp))
					cout << "Success.\n";
				else
					cout << "Failed.\n";
				break;

			case 2:
				if(list.delete_data(&temp))
					cout << "Successfully deleted " << temp << ".\n";
				else
					cout << "Failed.\n";
				break;
			case 3:
				list.display();
				break;
		}
	}while(choice != 0);
}