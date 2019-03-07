#include<iostream>
using namespace std;
template <class T>
void bub_sort(T *arr, int n)
{
	T temp;
	int i, j;
	for (i = 0; i < n - 1; i++)  
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
}

int main()
{
	int size_of_array, index;
	int *int_arr;
	float *float_arr;
	double *double_arr;
	char *arr;
	int choice;
	while (1)
	{
		cout << "\n Enter the choice\n 0.EXIT 1.Integer 2.Float 3.Double 4.Characters \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the size of integer array : ";
			cin >> size_of_array;
			if (size_of_array <= 0)
			{
				cout << "\nNot a valid size\n"; break;
			}
			int_arr = new int[size_of_array];
			cout << "\n Enter " << size_of_array << " integer values\n";
			for (index = 0; index < size_of_array; index++)
			{
				cin >> int_arr[index];
			}
			bub_sort(int_arr, size_of_array);
			cout << "\n Elements in sorting order \n";
			for (index = 0; index < size_of_array; index++)
			{
				cout << " " << int_arr[index];
			}
			delete[] int_arr;
			break;
		case 2:
			cout << "Enter the size of Float array : ";
			cin >> size_of_array;
			if (size_of_array <= 0)
			{
				cout << "\nNot a valid size\n"; break;
			}
			float_arr = new float[size_of_array];
			cout << "\n Enter " << size_of_array << " Float values\n";
			for (index = 0; index < size_of_array; index++)
			{
				cin >> float_arr[index];
			}
			bub_sort(float_arr, size_of_array);
			cout << "\n Elements in sorting order \n";
			for (index = 0; index < size_of_array; index++)
			{
				cout << " " << float_arr[index];
			}
			delete[] float_arr;
			break;
		case 3:
			cout << "Enter the size of Double array : ";
			cin >> size_of_array;
			if (size_of_array <= 0)
			{
				cout << "\nNot a valid size\n"; break;
			}
			double_arr = new double[size_of_array];
			cout << "\n Enter " << size_of_array << " Double values\n";
			for (index = 0; index < size_of_array; index++)
			{
				cin >> double_arr[index];
			}
			bub_sort(double_arr, size_of_array);
			cout << "\n Elements in sorting order \n";
			for (index = 0; index < size_of_array; index++)
			{
				cout << " " << double_arr[index];
			}
			delete[] double_arr;
			break;
		case 4:
			cout << "Enter the size of character array : ";
			cin >> size_of_array;
			if (size_of_array <= 0)
			{
				cout << "\nNot a valid size\n"; break;
			}
			arr = new char[size_of_array];
			cout << "\n Enter " << size_of_array << " characters\n";
			for (index = 0; index < size_of_array; index++)
			{
				cin >> arr[index];
			}
			bub_sort(arr, size_of_array);
			cout << "\n Elements in sorting order \n";
			for (index = 0; index < size_of_array; index++)
			{
				cout << " " << arr[index];
			}
			delete[] arr;
			break;
		case 0:
			cout << "\n";
			return 0;
			break;
		default:
			cout << "\n Please enter valid choice \n";
			break;
		}
	}
}