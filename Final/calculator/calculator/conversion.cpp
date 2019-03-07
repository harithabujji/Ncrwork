#include<string>

#include<queue>
#include<stack>
#include<iostream>
using namespace std;

//Function to return precedence of operators 
int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

extern string infixToPostfix(string s)
{
	std::stack<char> st;
	st.push('N');
	int l = s.length();
	string ns,ns1;
	char c;
	for (int i = 0; i < l; i++) {
		if (isdigit(s[i])) {
			ns += s[i];
		}
		else if (s[i] == '(') {
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			while (st.top() != 'N'&&st.top() != '(') {
				c = st.top();
				st.pop();
				ns += c;
			}
			if (st.top() == '(') {
				c = st.top();
				st.top();
			}
		}
		else {
			while (st.top() != 'N'&&prec(s[i]) <= prec(st.top())) {
				c = st.top();
				st.pop();
				ns += c;
			}
			st.push(s[i]);
		}
	}
	while (st.top() != 'N') {
		c = st.top();
		st.pop();
		ns += c;
	}
	l = ns.length();
	cout << ns << endl;
	for (int i = 0; i < l; i++) {
		if (ns[i] == '(') {
			continue;
		}
		ns1 += ns[i];
	}
	cout << ns1 << endl;
	return ns1;
}