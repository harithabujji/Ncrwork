#include<stdio.h>
#include<conio.h>
void convertBinaryToHexadecimal()
{
	long int decnum, rem, quot;
	int i = 1, j, temp;
	char hexdecnum[100];
	printf("Enter decimal number : ");
	scanf("%ld", &decnum);
	quot = decnum;//hi
	while (quot != 0)
	{
		temp = quot % 16;
		if (temp < 10)
		{
			temp = temp + 48;
		}
		else
		{
			temp = temp + 55;
		}
		hexdecnum[i++] = temp;
		quot = quot / 16;
	}
	printf("hexadecimal value of %d is :\n", decnum);
	for (j = i - 1; j>0; j--)
	{
		printf("%c", hexdecnum[j]);
	}
}
void convertHexaDecimalToBinary()
{

	char binarynum[MAX], hexa[MAX];
	long int i = 0;

	printf("Enter the value for hexadecimal ");
	scanf_s("%s", hexa);
	printf("\n binary value of %s : ");
	while (hexa[i])
	{
		switch (hexa[i])
		{
		case '0':
			printf("0000"); break;
		case '1':
			printf("0001"); break;
		case '2':
			printf("0010"); break;
		case '3':
			printf("0011"); break;
		case '4':
			printf("0100"); break;
		case '5':
			printf("0101"); break;
		case '6':
			printf("0110"); break;
		case '7':
			printf("0111"); break;
		case '8':
			printf("1000"); break;
		case '9':
			printf("1001"); break;
		case 'A':
			printf("1010"); break;
		case 'B':
			printf("1011"); break;
		case 'C':
			printf("1100"); break;
		case 'D':
			printf("1101"); break;
		case 'E':
			printf("1110"); break;
		case 'F':
			printf("1111"); break;
		case 'a':
			printf("1010"); break;
		case 'b':
			printf("1011"); break;
		case 'c':
			printf("1100"); break;
		case 'd':
			printf("1101"); break;
		case 'e':
			printf("1110"); break;
		case 'f':
			printf("1111"); break;
		default:
			printf("\n Invalid hexa digit %c ", hexa[i]);
			return 0;
		}
		i++;
	}

}

int main()
{
	int ch;
	long int decnum;
	int num;
	while (1)
	{
		printf("\nEnter the option : 1) binary to hexadecimal 2) hexadecimal to binary :");
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1:
			convertBinaryToHexadecimal();
			break;
		case 2:
			convertHexaDecimalToBinary());
			break;
		default:
			printf("\n Enter the correct option");
		}
		printf("\n If you want to terminate Enter ZERO else Any Number:");
		scanf_s("%d", &ch);
		if (ch == 0)
		{
			getchar();
			return 0;

		}

	}

	return 0;
}
