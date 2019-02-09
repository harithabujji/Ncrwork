#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char * s[] = { "we will teach you how to","Move a mountain","Level a building","Erase the past","Make a million" };
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; s[i][j] != '\0'; j++) {
			if (s[i][j] == 'e' || s[i][j] == 'E') {
				count++;
			}
		}
	}
	printf("the no. of e's %d\n", count);
	getchar();
	getchar();
	return 0;
}