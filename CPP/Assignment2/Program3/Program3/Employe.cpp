
#include<iostream>
#include<string>
using namespace std;
class Employe
{
	string name;
	int empno;
	int salary;
public:
	static int emp_count;
	Employe()
	{
		empno = 0;
		salary = 0;
	}
	~Employe()
	{}
	friend istream & operator>>(istream &in, Employe &s);
	friend void display(Employe *s, int n);
};
int Employe::emp_count = 1;
istream & operator>>(istream &in, Employe &s)
{
	cout << "\n Enter Employe name : ";
	in >> s.name;
	s.empno = Employe::emp_count;
	Employe::emp_count = Employe::emp_count + 1;
	cout << "\n Enter Salary : " << endl;
	in >> s.salary;
	return in;
}

void display(Employe *s, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cout << s[i].empno << "\t \t" << s[i].name << " \t \t " << s[i].salary << endl;
	}
}
int main()
{
	int n, i;
	cout << "\n Enter number of Employes : ";
	cin >> n;
	Employe *s = new Employe[n];
	for (i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	cout << "Employenumber \t Name \t \t Salary \t" << endl;
	display(s, n);
	system("pause");
}