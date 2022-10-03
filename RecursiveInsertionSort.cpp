// Recursive C++ program for insertion sort
#include <iostream>
using namespace std;

void insertionSortRecursive(int arr[], int size)
{
	if (size <= 1)
		return;
	insertionSortRecursive( arr, size-1 );
	int last = arr[size-1];
	int j = size-2;
	while (j >= 0 && arr[j] > last)
	{
		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1] = last;
}

void printer(int arr[], int size)
{
	for (int i=0; i < size; i++)
		cout << arr[i] <<" ";
}

int main()
{
	int arr[] = {2, 11, 3, 5, 16};
	int n = sizeof(arr)/sizeof(arr[0]);

	insertionSortRecursive(arr, n);
	printer(arr, n);

	return 0;
}
