#define _CRT_-SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class String
{
	char *sptr; int len;
public:
	String()
	{
		sptr = NULL;
	}
	String(char *n)
	{
		len = strlen(n);
		sptr = new char[len + 1];
		strcpy(sptr, n);
	}
	String(String &s)
	{
		len = s.len;
		sptr= new char[(len )+ 1];
		strcpy(sptr, s.sptr);
	}
	~String()
	{
		//[] sptr;
	}
	String operator+(String s)
	{
		String res;
		res.len = len + s.len;
		res.sptr = new char[(res.len)+1];
		strcpy(res.sptr, sptr);
		strcat(res.sptr, s.sptr);
		return res;
	}
	char operator[](int i)
	{
		return sptr[i];
	}
	friend void display(String s1);
	friend istream & operator>>(istream &in, String &s);
	friend ostream & operator<<(ostream &out, String &s);
};
void display(String s1)
{
	cout << "\n" << s1.sptr << "  " << s1.len << endl;
}

istream & operator>>(istream &in, String &s)
{
	char n[50];
	cout << "\n Enter string : ";
	in >> n;
	s.len = strlen(n);
	s.sptr = new char[(s.len)+1];
	strcpy(s.sptr, n);
	return in;
}
ostream & operator<<(ostream &out, String &s1)
{
	cout << "\n" << s1.sptr << "  " << s1.len << endl;
	return out;
}
int main()
{
	char n[10];
	cout << "\n Enter the string : ";
	cin >> n;
	String s,s1(n),s2,s3;
	s2 = s1;
	display(s1);
	display(s2);
	s = s1 + s2;
	display(s);
	cin >> s3;
	cout << s3;
	int i;
	cout << "\n Enter the index : ";
	cin >> i;
	char c = s3[i];
	cout << " The value at index " << i << " is :" << c;
	cout << "\n";
	system("pause");
	return 0;
}