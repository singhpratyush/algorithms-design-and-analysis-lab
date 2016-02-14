#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int nargs, char ** args)
{
	if(nargs != 2 && nargs != 3)
	{
		cerr << "usage : ./number_generator <number of numbers> [<seed = current time>]\n";
		return 1;
	}

	srand( (nargs == 2)? time(NULL):atoi(args[2]) );

	ofstream f;
	f.open("numbers.txt");
	int n = atoi(args[1]);
	f << n << endl;
	while(n-- > 0)
	{
		f << rand() % 100 << " ";
	}
}