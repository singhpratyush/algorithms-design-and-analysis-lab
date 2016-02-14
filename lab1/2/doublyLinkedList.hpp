/*
Class definition for doubly linked list having a key and an integer data.
*/

#include <iostream>

using namespace std;

class node
{
	unsigned int key;
	int data;
	node *left, *right;

public:
	node(unsigned int keyArgument, int dataArgument)
	{
		key = keyArgument;
		data = dataArgument;
		left = right = NULL;
	}

	node()
	{
		node(0,0);
	}

	void setState(unsigned int keyArgument,int dataArgument)
	{
		key = keyArgument;
		data = dataArgument;
	}

	void setLeft(node *ptr)
	{
		left = ptr;
	}

	void setRight(node *ptr)
	{
		right = ptr;
	}

	unsigned int getKey()
	{
		return key;
	}

	int getData()
	{
		return data;
	}

	node *getRight()
	{
		return right;
	}

	node *getLeft()
	{
		return left;
	}

	~node(){}
};

class doublyLinkedList
{
	node *head, *tail;

public:

	doublyLinkedList()
	{
		head = tail = NULL;
	}

	bool push(unsigned int key, int data)
	{
		if(hasKey(key))
			return false;

		node *temp = new node(key, data);
		
		if(temp == NULL)
			return false;

		if(head == NULL)
		{
			head = tail = temp;
			return true;
		}

		temp -> setRight(head);
		head -> setLeft(head);
		head = temp;
		return true;
	}

	bool pushBack(unsigned int key, int data)
	{
		if(hasKey(key))
			return false;

		node *temp = new node(key, data);

		if(temp == NULL)
			return false;

		if(head == NULL)
		{
			head = tail = temp;
			return true;
		}

		temp -> setLeft(tail);
		tail -> setRight(temp);
		tail = temp;
		return true;
	}

	void display()
	{		
		node *temp;

		temp = head;

		while(temp != NULL)
		{
			cout << temp ->getKey() << "( " << temp -> getData() << " )" << endl;
			temp = temp -> getRight();
		}
	}

	bool deleteKey(unsigned int key)
	{
		if(head == NULL)
			return false;

		node *temp = head;

		while(temp -> getKey() != key)
		{
			temp = temp -> getRight() ;
			if(temp == NULL)
				return false;
		}

		if(temp -> getRight() == NULL && temp -> getLeft() == NULL)
		{
			delete temp;
			head = tail = NULL;
			return true;
		}

		if(temp == head)
		{
			head = head -> getRight();
			temp -> setRight(NULL);
			delete temp;
			return true;
		}

		if(temp == tail)
		{
			tail = tail -> getLeft();
			temp -> setLeft(NULL);
			delete temp;
			return true;
		}

		node *right = temp -> getRight(), *left = temp -> getLeft();
		right -> setLeft( left );
		left -> setRight( right );
		temp -> setRight(NULL);
		temp -> setLeft(NULL);
		delete temp;
		return true;
	}

	bool hasKey(unsigned int key)
	{
		node *temp = head;
		do
		{
			if(temp == NULL)
				return false;

			if(temp -> getKey() == key)
				return true;

			temp = temp -> getRight();
		}while(true);
	}

	int getData(unsigned int key)
	{
		node *temp = head;
		while(temp -> getKey() != key)
			temp = temp -> getRight();
		return temp -> getData();
	}

};