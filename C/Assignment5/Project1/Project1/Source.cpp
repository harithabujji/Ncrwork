#include<iostream>
using namespace std;


class time
{
	int hr;
	int min;
	int sec;
public:
	time()
	{
		hr = min = sec = 0;
	}
	time(int a, int b, int c)
	{
		hr = a;
		min = b;
		sec = c;
	}
	time(time &t1, time &t2)
	{
		hr = t1.hr + t2.hr;
		
		min = t1.min + t2.min;
		if (min >= 60)
		{
			hr++;
			min = min - 60;
		}
		sec = t1.sec + t2.sec;

	}
	void display_time()
	{
		printf("%d:%d:%d", hr, min, sec);
	}

};

int main()
{
	time t_1(5,30,0),t_2(5,30,5);
	time t_3(t_1,t_2);
	
	t_3.display_time();
	system("pause");
	return 0;
}