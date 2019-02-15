#include<iostream>
using namespace std;
class Swap
{
	int x, y;
    public:
	void swap1(int x, int y)
	{
		int temp;
		temp = x;
		x = y;
		y = temp;
		cout << "\nswapped values: " << x << "\t" << y;
	}
	void swap2(int *x, int *y)
	{
		int temp;
		temp = *x;
		*x = *y;
		*y = temp;
		cout << "\nswapped value : " << *x << "\t" << *y;
	}

};
int main()
{
	int x, y, n;
	Swap s;
	cout << "enter two values to be swapped\n";
	cin >> x >> y;
	cout << "\nfor CALL BY VALUE press1";
	cout << "\nfor CALL BY REFERENCE press2";
	cin >> n;
	switch (n)
	{
	case 1:

		cout << "\nCALL BY VALUE";
		cout << "\nvalues before swap " << x << "\t" << y;
		s.swap1(x, y);
		cout << "\nafter swap outside of function";
		cout << "\n x= " << x << "\n y= " << y;
		break;
	case 2:
		cout << "\nCALL BY REFERENCE";
		cout << "\nvalue before swap  " << x << y;
		s.swap2(&x, &y);
		cout << "\nafter swap outside of function  " << x << y;
		break;
	}
	system("pause");
	return 0;
}