#include<stdio.h>
#include<stdlib.h>
int replace(char *s)
{
	int i = 0, count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
		{
			s[i] = '-';
			count++;
		}
		printf("%c", s[i]);
		i++;
		
	}
	return count;
}
int main()
{
	char *s = (char *)malloc(20);
	printf("\n Enter the string:");
	scanf_s("%[^\n]s", s,20);
	int no_of_spaces = replace(s);
	printf("\n Number of spaces are : %d", no_of_spaces);
	getchar();
	getchar();
	return 0;
}