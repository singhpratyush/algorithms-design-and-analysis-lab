/*
Class definition for special queue mentioned in Question 6.
*/

#include <iostream>

using namespace std;

class node
{
	int data;
	node *next;
public:

	node(int a)
	{
		data = a;
		next = NULL;
	}

	void setNext(node *a)
	{
		next = a;
	}

	int getData()
	{
		return data;
	}

	node *getNext()
	{
		return next;
	}
};

class special_list
{
	node *head, *tail;
	int size;

public:

	special_list()
	{
		size = 0;
		head = tail = NULL;
	}

	bool insert_data(int data)
	{
		node *temp = new node(data);

		if(temp == NULL)
			return false;

		if(size == 0)
		{
			head = tail = temp;
			size ++ ;
			return true;
		}

		tail->setNext(temp);
		tail = temp;
		size++;
		return true;
	}

	void display()
	{
		cout << "Size : " << size << endl;
		cout << "Head : " << head->getData() << "Tail : " << tail->getData() << endl;
		node *temp = head;
		while(temp != NULL)
		{
			cout << temp->getData() << " --> ";
			temp = temp->getNext();
		}
		cout << "\n";
	}

	bool delete_data(int *a)
	{
		if(size == 0)
			return false;
		
		if(size <= 8)
		{
			*a = head -> getData();
			if(size == 1)
			{
				node *temp = head;
				head = tail = NULL;
				delete temp;
				size -- ;
				return true;
			}
			else
			{
				node *temp = head;
				head = head->getNext();
				temp->setNext(NULL);
				delete temp;
				size--;
				return true;
			}
		}
		else
		{
			if(size == 1)
			{
				*a = head->getData();
				node *temp = head;
				head = tail = NULL;
				delete temp;
				size--;
				return true;
			}

			node *temp = head;
			while(temp->getNext() != tail)
			temp = temp -> getNext();
			*a = temp->getNext()->getData();
			node *temp1 = temp->getNext();
			temp->setNext(NULL);
			delete temp1;
			size --;
			tail = temp;
			return true;
		}
	}
};