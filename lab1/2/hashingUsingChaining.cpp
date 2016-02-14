/*
Implementation of hashing using chaining.
*/

#include "doublyLinkedList.hpp"

using namespace std;

class chainedHashTable
{
	int size;
	doublyLinkedList *array;

public:

	chainedHashTable(int sizeArgument)
	{
		size = sizeArgument;
		array = new doublyLinkedList[size];
	}

	bool insert(unsigned int key, int data)
	{
		return array[key % size].push(key , data);
	}

	void search(unsigned int key)
	{
		int slot = key % size;
		if(array[slot].hasKey(key))
			cout << "Data is : " << array[slot].getData(key) << endl;
		else
			cout << "Not found.\n";
	}

	bool deleteKey(unsigned int key)
	{
		return array[key % size].deleteKey(key);
	}
};

int main(void)
{
	cout << "\nEnter size of hash table : ";
	int choice, data;
	unsigned int key;
	cin >> key;

	chainedHashTable table(key);

	do
	{
		cout << "\n0. Exit\n1. Insert\n2. Search\n3. Delete\nEnter your choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "\n***Insert Data***\n";
				cout << "\nEnter Key : ";
				cin >> key;
				cout << "Enter Data : ";
				cin >> data;
				if(table.insert(key, data))
					cout << "Success\n";
				else
					cout << "Insertion failed.\n";
				break;

			case 2:
				cout << "\n***Search Data***\n";
				cout << "\nEnter Key : ";
				cin >> key;
				table.search(key);
				break;

			case 3:
				cout << "\n***Delete Data***\n";
				cout << "\nEnter Key : ";
				cin >> key;
				if(table.deleteKey(key))
					cout << "Success.\n";
				else
					cout << "Deletion failed.\n";
		}
	}while(choice != 0);
	return 0;
}