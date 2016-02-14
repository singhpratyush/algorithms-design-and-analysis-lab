/*
Solving tower of hanoi.
*/

#include <iostream>
#include "../4/stack.hpp"

using namespace std;

stack *a[3];

long long int steps = 0;

void show_towers()
{
	for(int i = 0 ; i < 3 ; i ++ )
	{
		cout << "Tower " << i << " >> " ;
		a[i]->display();
	}
	cout << endl << endl;
}

void solve_towers(int size, int from, int use, int to)
{
	if(size > 0)
	{
		solve_towers(size-1, from, to, use);
		int temp;
		a[from]->pop(&temp);
		a[to]->push(temp);
		steps++;
		show_towers();
		solve_towers(size-1, use, from, to);
	}
}

int main(void)
{
	cout << "Enter size of tower : ";
	int size ;
	cin >> size;

	for(int i = 0 ; i < 3 ; i ++ )
		a[i] = new stack(size);

	for(int i = size ; i > 0 ; i -- )
		a[0]->push(i);

	show_towers();
	solve_towers(size, 0, 1, 2);
	cout << "Number of steps : " << steps << endl;
	return 0;
}