/*
Class definition for hasing using probing object.
*/

#include <iostream>
#include "element.hpp"

using namespace std;

class probing
{
	element *thing;
	int size;

public:
	probing(int s)
	{
		size = s;
		thing = new element[size];
	}

	bool insert_element(int key, int data)
	{

		if(key < 0)
			return false;

		if(keyAlreadyExists(key))
		{
			return false;
		}

		int slot;
		int start_slot = slot = key % size;
		while(true)
		{
			if(thing[slot].isFree())
			{
				thing[slot].setAttr(key, data);
				return true;
			}
			else
				slot = (slot+1)%size;

			if(slot == start_slot)
				return false;
		}
	}

	bool delete_element(int key)
	{

		if(key < 0)
			return false;

		int start_slot, slot;
		start_slot = slot = key % size;

		while(true)
		{
			if(thing[slot].getKey() == key)
			{
				thing[slot].setFree();
				return true;
			}
			else
			{			
				if(!thing[slot].isEverOccupied())
					return false;
				slot = (slot+1)%size;
			}

			if(slot == start_slot)
				return false;
		}
	}

	void display()
	{
		for(int i = 0 ; i < size ; i ++ )
		{
			cout << "Slot " << i+1 << ": ";
			if(!thing[i].isFree())
				cout << thing[i].getKey() << " ( " << thing[i].getData() << " )" << endl;
			else
			{
				if(thing[i].isEverOccupied())
					cout << "Deleted.\n";
				else
					cout << "Never Occupied.\n";
			}
		}
	}

	bool keyAlreadyExists(int a)
	{
		int start_slot, slot;
		start_slot = slot = a%size;

		do
		{
			if(!thing[slot].isEverOccupied())
				return false;


			if(thing[slot].getKey() == a && !thing[slot].isFree())
				return true;

			slot = (slot+1)%size;
		}while(slot != start_slot);
		return false;
	}
};