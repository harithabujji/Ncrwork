#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n, j, i = 0;
	printf("Enter the number of strings:");
	scanf_s("%d", &n);
	j = n;
	char *name = (char *)malloc(20);
	//char **s = (char **)malloc(n * sizeof(char *));
	char *s[20];

	for (i = 0; i < n; i++)
	{
		s[i] = (char *)malloc(20);
	}
	i = 0;
	while (n > 0)
	{
		printf("\n Enter the string :");
		getchar();
		scanf_s("%[^\n]s", s[i], 20);
		i++;
		n--;
	}
	for (i = 0; i < j; i++)
	{
		printf("\n %s", s[i]);
		free(s[i]);
	}
	getchar();
	getchar();
	return 0;

}