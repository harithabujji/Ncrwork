#include<stdio.h>
#include<stdlib.h>
void reverse(char *s)
{
	if (*s)
	{
		reverse(s + 1);
		printf("%c", *s);

	}
}
int main()
{
	char *s = (char *)malloc(20);
	printf("\n Enter the string :");
	scanf_s("%[^\n]s", s, 20);
	reverse(s);
	getchar();
	getchar();
}