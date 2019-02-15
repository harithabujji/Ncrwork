#include<iostream>
using namespace std;


class matrix
{
	int* A;
	int row;
	int col;

public:
	matrix()
	{

	}
	matrix(int s1, int s2)
	{   
		int i, j;
		row = s1;
		col = s2;
		A = (int *)malloc(row*col * sizeof(int));
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				cout << "ënterA[" << i << "][" << j << "]=" << endl;
				cin >> *A([i][j]);
			}
		}
	}

	void display()
	{
		int i, j;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				cout << A[i][j] << endl;
			}
		}
	}
	
};


int main()
{
	matrix m(2,2);
	m.display();
	system("pause");
	return 0;


}