
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	FILE* fp=NULL;
	fp=fopen( "text1.txt", "a+");
	char ch;
	int i=0;
	fputs("santhosh", fp);
	fclose(fp);
	fp = fopen("text1.txt", "r");
	ch = fgetc(fp);

	while (ch != EOF)
	{
		i++;
		ch = fgetc(fp);
	}
	printf("%d", i);
	getchar();
	getchar();
	return 0;

 }
