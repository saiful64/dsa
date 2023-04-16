#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
	int pivot = arr[s];
	int cnt = 0;

	for (int i = s + 1; i <= e; i++)
	{
		if (arr[i] < pivot)
			cnt++;
	}

	// Place pivot at correct index
	int pivotIndex = s + cnt;
	swap(arr[s], arr[pivotIndex]);

	int i = s;
	int j = e;

	while (i < pivotIndex && j > pivotIndex)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] >= pivot)
			j--;

		if (i < pivotIndex && j > pivotIndex)
			swap(arr[i++], arr[j--]);
	}

	return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
	if (s >= e)
		return;

	int pIndex = partition(arr, s, e);

	quickSort(arr, s, pIndex - 1);
	quickSort(arr, pIndex + 1, e);
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}
