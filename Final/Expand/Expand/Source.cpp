#include <regex>
#include<string>
#include<ctype.h>
#include<stdio.h>
#include<iostream>
using namespace std;
/*
2.	Write a function expand (s1, s2) which expands 
shorthand notations of s1 like a-d into abcd and 0-9 to 0123456789 in s2.
For example if the string in s1 is 0123a-e1-4 then s1 is expanded in s2 to 0123abcde1234. 
(this program is from assignment 4, program no.- 13)
*/


int expand_string(string input)
{
	string s1;
	int l = input.length();
	int flag1 = 0, flag2 = 0;
	if (input[0] == '-' || input[l - 1] == '-')
		throw "cannot have hyphen at front or back";
	for (int i = 0; i < input.length(); i++)
	{
		if (i + 1 < input.length() && input[i + 1] != '-' || i == input.length() - 1)
		{
			s1 += input[i];
		}
		else if (i + 1 < input.length() && i + 2 < input.length() && input[i + 1] == '-'&&input[i + 2] == '-')
		{
			cout << "invalid";
			system("pause");
			return 0;
		}
		else
		{
			if (isdigit(input[i]) && i + 1 < input.length() && i + 2 < input.length() && input[i + 1] == '-')
			{
				if (i + 2 < input.length() && isdigit(input[i + 2]) && input[i] < input[i + 2])
				{
					int x = (int)input[i];
					x = x - 48;
					int y = (int)input[i + 2];
					y = y - 48;
					for (int i = x; i <= y; i++) {
						if (flag1 == 1) {
							flag1 = 0;
							continue;
						}
						char c = (char)(i + 48);
						s1 += c;
					}
					i = i + 2;
					if (input[i + 1] == '-') {
						flag1 = 1;
						i = i - 1;
					}
				}
				else {
					cout << "invalid";
					system("pause");
					return 0;
				}
			}
			else {
				if (isalpha(input[i]) && i + 1 < input.length() && i + 2 < input.length() && input[i + 1] == '-') {
					if (i + 2 < input.length() && isalpha(input[i + 2]) && input[i + 2] - input[i] <= 26) {
						int x = (int)input[i];
						int y = (int)input[i + 2];
						char c;
						for (int i = x; i <= y; i++) {
							if (flag2 == 1) {
								flag2 = 0;
								continue;
							}
							c = (char)i;
							s1 += c;
						}

						i = i + 2;
						if (input[i + 1] == '-') {
							flag2 = 1;
							i = i - 1;
						}
					}
					else {
						cout << "invalid";
						system("pause");
						return 0;
					}
				}
			}
		}
	}

	cout << "\nResultant String is : " << s1<<endl;
	return 1;
}
int main() {
	string input;
	try
	{
		cout << "Enter string :" << endl;
		cin >> input;
		expand_string(input);
	}
	//in case of exception
	catch (const char*msg)
	{
		cout << msg;
	}
	system("pause");
	return 0;
}

