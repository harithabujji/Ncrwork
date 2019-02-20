#include<iostream>
using namespace std;


class stack
{
	int top;
	int *stk;
	int size;

public:
	stack()
	{
		int n;
		cout << "\n Enter size:";
		cin >> n;
		stk = new int[n];
		size = n;
		top = -1;
	}
	bool isfull()
	{
		if (top == (size - 1))
			return true;
		else
			return false;
	}
	int isempty()
	{
		return (top == -1);
	}

	void push(int x)
	{
		if (!isfull())
			stk[++top] = x;
		else {
			cout << "stack is full";
		}
	}
	int seek()
	{
		if (!isempty())
			return stk[top];
		else
		{
			cout << "stack is empty";
			return -2;
		}
	}
	int pop()
	{
		if (!isempty())
			return stk[top--];
		else
		{
			cout << "stack is empty";
			return -2;
		}

	}
	void display()
	{
		int i = 0;
		for (i = 0; i < top+1; i++)
		{
			cout << "  " << stk[i];
		}
		cout << "\n";
	}
	
};


int main()
{
	int i;
	stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.display();
	s1.pop();
	s1.display();
	cout << "\n";
	system("pause");
	return 0;
}