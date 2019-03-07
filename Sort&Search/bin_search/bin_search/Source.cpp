#include<iostream>
using namespace std;
int bin_search(int *arr, int size_of_array,int element)
{
	int low = 0, high = size_of_array - 1, mid;
	while (low <= high)
	{
		mid = low + high / 2;
		if (arr[mid] == element)
		{
			return mid + 1;
		}
		else if (arr[mid] > element)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return - 1;
}
int main()
{
	int size_of_array,index,element;
	cout << "Enter the size of array : ";
	cin >> size_of_array;
	if (size_of_array <= 0)
	{
		cout << "\nPlease enter the valid size\n";
		system("pause");
		return 0;
	}
	int *arr = new int[size_of_array];
	cout << "\n Enter " << size_of_array << " values in ascending order \n";
	for (index = 0; index < size_of_array; index++)
	{
		cin >> arr[index];
	}
	for (index = 0; index < size_of_array-1; index++)
	{
		if (arr[index] > arr[index + 1])
		{
			cout << "\n Elements are not in sorted order" << endl;
			delete[]arr;
			system("pause");
			return -1;
		}
	}
	cout << "Enter the element to search : ";
	cin >> element;
	int is_found=bin_search(arr, size_of_array,element);
	if (is_found == -1)
	{
		cout << "\n Element is not found" << endl;
	}
	else
	{
		cout << "\n Element " << element << " is found at " << is_found << " position" << endl;
	}
	delete []arr;
	cout << "\n";
	system("pause");
	return 0;
}