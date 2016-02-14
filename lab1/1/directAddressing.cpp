/*
Implementation of direct addressing.
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	char data[65535][10];
	int choice;

	do
	{
		int key;
		cout << "0. Exit\n1. Insert\n2. Delete\n3. Search\n";
		cin >> choice;
		if(choice == 1)
		{
			cout << "Enter key : " ;
			cin >> key;
			cout << "Enter data : " ;
			cin >> data[key];
		}
		else if(choice == 2)
		{
			cout << "Enter key : ";
			cin >> key;
			if(!strcmp(data[key],""))
				cout << "Not found.\n";
			else
			{
				strcpy(data[key],"");
				cout << "Deleted.\n";
			}
		}
		else if(choice == 3)
		{
			cout << "Enter key : ";
			cin >> key;
			if(!strcmp(data[key],""))
				cout << "Not found.\n";
			else
				cout << "Data is " << data[key] << endl;
		}
		else if(choice == 0)
			return 0;
		else
			cout << "Invalid choice.. Try again.\n";
	}while(true);
}