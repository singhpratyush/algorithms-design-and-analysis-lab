#include <iostream>
using namespace std;

class group
{
public:
	int startIndex, endIndex;
};

int main(void)
{
	int size;
	cin >> size;
	int arr[size];

	for(int i = 0 ; i < size ; i ++ )
		cin >> arr[i];


	merge_sort_sdm(arr, 0, size-1);

	for(int i = 0 ; i < size ; i ++ )
		cout << arr[i] << " " ;
	cout << endl;

	return 0;
}