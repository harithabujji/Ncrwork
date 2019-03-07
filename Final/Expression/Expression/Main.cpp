#include<string>
#include<iostream>
using namespace std;
int evaluate(string);

int main() 
{
	string expression;
	cin >> expression;
	cout << evaluate(expression) << "\n";
	system("pause");
	return 0;
}

