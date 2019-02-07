#include<stdio.h>
int main()
{
	int basic_salary, da, hra, gross_salary;
	printf("Enter the basic salary:");
	scanf_s("%d", &basic_salary);
	if (1 <= basic_salary && basic_salary <= 4000)
	{
		da = 50;
		hra = 10;
	}
	else if (4001 <= basic_salary && basic_salary <= 8000)
	{
		da = 60;
		hra = 20;
	}
	else if (8001 <= basic_salary && basic_salary <= 12000)
	{
		da = 70;
		hra = 25;
	}
	else
	{
		da = 80;
		hra = 30;
	}
	gross_salary = basic_salary + ((basic_salary*da) / 100) + ((basic_salary*hra) / 100);
	printf("\n Gross salary for %d is : %d",)
}