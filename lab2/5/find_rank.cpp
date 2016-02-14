#include <iostream>

using namespace std;

int position(int *arr, int element, int start, int end)
{
	int actualStart = start;
	while( start <= end )
	{
		int mid = (start + end)/2;
		if(arr[mid] > element)
			end = mid - 1;
		else if(arr[mid] < element)
			start = mid + 1;
		else
			return mid - actualStart + 1;
	}
	return end - actualStart + 1;
}

int main(void)
{
	int size;
	cin >> size;
	int arr[size];
	
	for(int i = 0 ; i < size ; i ++ )
		cin >> arr[i];

	int k, index_element;
	cin >> k;

	cin >> index_element;

	if(index_element < k)
		cout << index_element + position(arr, arr[index_element], k, size-1) + 1;
	else if (index_element > k)
		cout << index_element - k + position(arr, arr[index_element], 0, k-1) + 1;
	else
		cout << 1;

	cout << endl;

	return 0;
}