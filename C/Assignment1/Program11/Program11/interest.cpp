#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int power(int x, unsigned int y)
{
	if (y == 0)
		return 1;
	if (y % 2 == 0)
		return power(x, y / 2) * power(x, y / 2);
	return x * power(x, y / 2) * power(x, y / 2);
}
int main() {
	int p, t, r;
	printf("\nenter amount:");
	scanf_s("%d", &p);
	printf("\nenter time period:");
	scanf_s("%d", &t);
	printf("\nenter rate");
	scanf_s("%d", &r);
	int si = p*t*r / 100;
	int c1 = p*power((1 + r), t);
	int c2 = p*power((1 + (r / 2)), 2 * t);
	int c3 = p*power((1 + (r / 4)), 4 * t);
	int c4 = p*power((1 + (r / 12)), 12 * t);
	int c5 = p*power((1 + (r / 365)), 365 * t);
	printf("\n simple interest--%d \n compound yearly--%d\n compound half--%d \n compound quarterly--%d \n compound monthly--%d\n compound daily--%d ", si, c1, c2, c3, c4, c5);
	getchar();
	getchar();
}