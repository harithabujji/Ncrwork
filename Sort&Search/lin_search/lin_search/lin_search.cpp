#include<iostream>
using namespace std;
template <class T>
void lin_search(T *arr, int size_of_array, T element)
{
	for (int i = 0; i < size_of_array; i++)
	{
		if (arr[i] == element)
		{
			cout << "\n Item found at position = " << i + 1 << "\n\n";
			return;
		}
	}
	cout << "\nNot Found\n\n";
}
int main()
{
	int size_of_array, index, int_element;
	int *int_arr;
	float *float_arr,float_ele;
	double *double_arr,dou_ele;
	int choice;
	while (1)
	{
		cout << "\n Enter the choice\n 1.Integer 2.Float 3.Double 0.EXIT \n";
		cin >> choice;
		switch (choice)
		{
		case 1: 
			cout << "Enter the size of integer array : ";
			cin >> size_of_array;
			if (size_of_array <= 0)
			{
				cout << "\nNot a valid size\n";break;
			}
			int_arr = new int[size_of_array];
			cout << "\n Enter " << size_of_array << " integer values\n";
			for (index = 0; index < size_of_array; index++)
			{
				cin >> int_arr[index];
			}
			cout << "Enter the integer element to search : ";
			cin >> int_element;
			lin_search(int_arr, size_of_array, int_element);
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
			cout << "Enter the float element to search : ";
			cin >> float_ele;
			lin_search(float_arr, size_of_array, float_ele);
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
			cout << "Enter the double element to search : ";
			cin >> dou_ele;
			lin_search(double_arr, size_of_array, dou_ele);
			delete[] double_arr;
			break;
		case 0:
			cout << "\n";
			system("pause");
			return 0;
			break;
		default:
			cout << "\n Please enter valid choice \n";
			break;
		}
	}
}