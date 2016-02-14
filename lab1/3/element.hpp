/*
Class definition of elements in hash table that uses probing.
*/

class element
{
	int data, key;
	bool is_EverOccupied, is_Free;

public:
	element()
	{
		is_EverOccupied = false;
		is_Free = true;
		key = -1;
	}

	void setAttr(int a, int b)
	{
		is_EverOccupied = true;
		is_Free = false;
		key = a;
		data = b;
	}

	bool isEverOccupied()
	{
		return is_EverOccupied;
	}

	void setFree()
	{
		is_Free = true;
	}

	bool isFree()
	{
		return is_Free;
	}

	int getKey()
	{
		return key;
	}

	int getData()
	{
		return data;
	}

};