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

void merge_sort_sdm(int *arr, int length, int *grpArr, int grpLength)
{
	if(grpLength == 0)
		return;

	int start = 0;
	int newGrpArr[grpLength], grpCtr = 0;
	for(int i = 0 ; i < grpLength ; i += 2 )
	{
		int mid = grpArr[i];
		int end = (i+1 <= grpLength)?grpArr[i+1]:grpArr[i];
		newGrpArr[grpCtr++] = end;
		merge(arr, start, mid, end);
		start = end + 1;
	}
	merge_sort_sdm(arr, length, newGrpArr, grpCtr-1);
}

int main(void)
{
	int size;
	cin >> size;
	int arr[size];

	int groupArr[size], grpPos = 0;

	for(int i = 0 ; i < size ; i ++ )
		cin >> arr[i];

	for(int i = 0 ; i < size-1 ; i ++ )
		if(arr[i] > arr[i+1])
			groupArr[grpPos++] = i;

	groupArr[grpPos] = size-1;

	merge_sort_sdm(arr, size, groupArr, grpPos);

	for(int i = 0 ; i < size ; i ++ )
		cout << arr[i] << " " ;
	cout << endl;

	return 0;
}