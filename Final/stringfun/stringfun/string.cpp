#include<iostream>
using namespace std;
#define MAX 100


int getlength(char* str) 
{
	int n;
	for (n = 0; str[n] != '\0'; n++);
	return n;
}

void reverseStr(char* str, int n)  //function to reverse a string
{
	char temp;
	for (int i = 0; i < n / 2; i++)
	{
		temp = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = temp;

	}
}

char* strcat(char* str1, char* str2)
{
	int i = 0, j = 0;
	int n1, n2;
	n1 = getlength(str1);
	n2 = getlength(str2);
	char* str = NULL;
	str = (char*)malloc((n1 + n2) * sizeof(char));
	for (i = 0; str1[i] != '\0'; i++)
		str[i] = str1[i];
	while (str2[j] != '\0')
	{
		str[i++] = str2[j++];

	}
	return str;

}
bool strcmp(char* st1, char* st2)
{
	if (getlength(st1) != getlength(st2))
		return false;
	else
	{
		int i = 0;
		while (st1[i] != '\0')
		{
			if (st1[i] != st2[i])
				return false;
			i++;
		}
		return true;

	}

}

int main()		//main program
{
	char* str = NULL;
	char* cstr = NULL;
	char* str1 = NULL;
	int n;
	str = (char*)malloc(sizeof(char)*MAX);  //dynamic allocation
	cin >> str;
	n = getlength(str);
	cstr = (char*)malloc((n + 1) * sizeof(char));
	for (int i = 0; i <= n; i++)
		cstr[i] = str[i];
	cout << "copied str:" << cstr << endl;
	reverseStr(str, n);   //function call for reversing a string
	cout << "reversed string:";
	cout << str << endl;

	str1 = strcat(str, cstr);
	cout << "after cuncation: ";
	cout << str1 << endl;
	cout << strcmp(str, cstr);
	system("pause");
	return 0;
}