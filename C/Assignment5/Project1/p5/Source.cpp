#include<math.h>
#include<iostream>
using namespace std;

class point
{
	int x;
	int y;
public:
	point()
	{
		x = y = 0;
	}
	point(int a, int b)
	{
		x = a;
		y = b;

	}
	float get_distance(point &temp)
	{
		float f;
		f =(float) (pow((x - temp.x) ,2) +pow((y - temp.y),2));
		f = sqrt(f);
		return f;
	}
};

int main()
{
	point p1(1, 2), p2(3, 4);
	float f;
	f= p1.get_distance(p2);
	cout << f;
	system("pause");
	return 0;
}