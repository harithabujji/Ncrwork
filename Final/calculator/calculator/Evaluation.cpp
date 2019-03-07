#include<string>

#include<queue>
#include<stack>
#include<iostream>
using namespace std;

double divi(double, double);
double addicalc(double, double);
double subcalc(double, double);
double mul(double, double);

extern int postfixeval(string s) {
	stack<double> st;
	st.push(0);
	double c1, c2;
	int i = 0;

	for (i = 0; s[i] != '\0'; i++) {
		if (isdigit(s[i])) {
			double a = (double)s[i];
			st.push(a - 48);
		}
		else {
			if (s[i] == '*') {
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				double s = mul(c1, c2);
				st.push(s);
			}
			if (s[i] == '/') {
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				double s = divi(c1, c2);
				st.push(s);
			}
			if (s[i] == '+') {
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				double s = addicalc(c1, c2);
				st.push(s);
			}
			if (s[i] == '-') {
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				double s = subcalc(c2, c1);
				st.push(s);
			}
		}

	}
	cout <<"\n Result is : "<< st.top();
	return 0;
}