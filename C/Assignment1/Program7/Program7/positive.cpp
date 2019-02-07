#include<stdio.h>
int main()
{
	int num = 1, sum = 0, max=-1, min=1000;
	printf("\nEnter the number:");
	scanf_s("%d", &num);
	if (num <= 0)
	{
		printf("\n given 0 positive values");
	}
	else 
	{
		while (num > 0)
		{
			sum = sum + num;
			if (max < num)
				max = num;
			if (min > num)
				min = num;
			printf("\nEnter the number:");
			scanf_s("%d", &num);
		}
		getchar();
		printf("\nMin value:%d", min);
		printf("\nMax value:%d", max);
		printf("\nSum value:%d", sum);
	}
	getchar();
}