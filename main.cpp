#include <iostream>
#include <utility>
#include <sstream>
using namespace std;

void quickSort(int *arr, int left, int right) 
{
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) 
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) 
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);

}

bool read(int *array, int size)
{
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);
	for (int i = 0; i < size; ++i)
	{
		if (!(stream >> array[i]))
		{
			cout << "An error has occured while reading input data." << endl;
			return false;
		}
	}
	return true;
}

void printArray(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << ' ';
}

int main()
{
	int size;
	string number;
	getline(cin, number);
	istringstream stream(number);
	if (!(stream >> size) || (size < 2))
	{
		cout << "An error has occured while reading input data." << endl;
		cin.get();
		return -1;
	}
	int *arr = new int[size];
	if (read(arr, size))
	{
		quickSort(arr, 0, size-1);
		cout << "Sorted array: \n";
		printArray(arr, size);
	}
	cin.get();
	return 0;
}
