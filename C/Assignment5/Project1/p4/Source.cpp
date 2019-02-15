#include<iostream>
using namespace std;
inline int add(int a, int b)
{
	return a + b;
}
inline int sub(int a, int b)
{
	return a - b;

}
inline int mul(int a, int b)
{
	return a*b;
}

int main()
{
	int ch;
	ch = add(1, 2);
	cout << ch << endl;
	ch = sub(2, 1);
	cout << ch << endl;
	ch = mul(2, 3);
	cout << ch << endl;
	system("pause");
	return 0;

}