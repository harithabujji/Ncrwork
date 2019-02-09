#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<string.h>
int main()
{
	char *string=(char *)malloc(20);
	int len;
    printf("Input a string to\n convert to upper case\n");
	scanf_s("%[^\n]s", string,20);
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= 'A'&&string[i] <= 'Z')
		string[i] = string[i] + 32;
		else if (string[i] >= 'a'&&string[i] <= 'z')
			string[i] = string[i] - 32;
		else
		{
		}
		printf("%c", string[i]);
		i++;
	}

	getchar();
	getchar();
	return  0;
}