#include <iostream>

using namespace std;

void merge(int *arr, int l, int mid, int r)
{
	int i;

	int left_size = mid - l + 1;
	int right_size = r - mid;

	int left[left_size], right[right_size];

	for(i = l ; i <= mid ; i ++ )
		left[i - l] = arr[i];

	for(i = mid+1 ; i <= r ; i ++ )
		right[i - mid - 1] = arr[i];

	int m = 0 , n = 0 ;

	for(i = l ; m < left_size && n < right_size ; i ++ )
		if (left[m] > right[n])
			arr[i] = right[n++];
		else
			arr[i] = left[m++];

	while( m < left_size)
		arr[i++] = left[m++];

	while( n < right_size)
		arr[i++] = right[n++];
}

void merge_sort(int *arr, int left, int right)
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}

int main(void)
{
	int length;
	cin >> length;

	int array[length];
	for(int i = 0 ; i < length ; i ++ )
		cin >> array[i];

	merge_sort(array, 0, length-1);

	for(int i = 0 ; i < length ; i ++ )
		cout << array[i] << " ";
}