#include<iostream>
using namespace std;
class Complex
{
	float real;
	float img;
public:
	Complex()
	{
		real = img = 0;
	}
	Complex(float x, float y)
	{
		real = x;
		img = y;
	}
	Complex(const Complex &c2)
	{
		real = c2.real;
		img = c2.img;
	}
	Complex operator+(Complex c)
	{
		Complex res;
		res.real = real + c.real;
		res.img = img + c.img;
		return res;
	}
	Complex operator-(Complex c2)
	{
		Complex res;
		res.real = real - c2.real;
		res.img = img - c2.img;
		return res;

	}
	Complex operator++(void)//prefix
	{
		real++;
		img++;
		return (*this);
	}
	Complex operator++(int)
	{
		Complex res;
		res.img = real++;
		res.img = img++;
		return  res;

	}
	Complex operator-(Complex c)
	{
		return  Complex((-c.real, -c.img));
	}
	void display()
	{
		cout << "result:" << real << "+i" << img;
	}
};
int main()
{
	Complex c1(2, 3), c2(4, 5);
	Complex c3;
	c3 = c1 + c2;
}