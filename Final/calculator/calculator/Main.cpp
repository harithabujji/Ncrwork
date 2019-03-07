#include<string>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
	
bool areParanthesisBalanced(string);
string infixToPostfix(string);
int postfixeval(string);

int main()
{
		stack<char> st;
		st.push('N');
        string expression, ns, ns1;
		cin >> expression;
		if (areParanthesisBalanced(expression)) 
		{
		//cout << "Balanced" << endl;
		}
		else
		{
			cout << "Not Balanced" << endl;
			system("pause");
			return 0;
		}
		expression = infixToPostfix(expression);
		postfixeval(expression);
		system("pause");
		return 0;
	}