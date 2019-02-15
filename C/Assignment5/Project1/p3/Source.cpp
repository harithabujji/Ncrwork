#include<iostream>
using namespace std;


class complex
{
	int real;
	int img;
public:
	complex()
	{
		real = img = 0;
	}
	complex(int a)
	{
		real = img = 0;
	}

	complex(int a, int b)
	{
		real = a;
		img = b;
	}

	complex(complex &c1, complex &c2)
	{
		real = c1.real + c2.real;
		img = c1.img + c2.img;
	}
	void display_complex()
	{
		cout << "real:" << real << "img:" << img << endl;
	}
	complex abc::mul(complex, complex);

};
class abc
{
	complex mul(complex &c1, complex &c2)
	{
		complex temp;
		temp.real = c1.real*c2.real - c1.img*c2.img;
		temp.img = c1.real*c2.img + c1.img*c2.real;
		return temp;
	}
};

int main()
{
	complex c1(1, 2), c2(2, 3);
	complex c3,c4(c1,c2);

	c4.display_complex();
	c3 = c3.mul(c1, c2);
	c3.display_complex();
	system("pause");
	return 0;
}