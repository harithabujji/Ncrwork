#include <stdio.h>
void isPalindrome(int n)
{
	int  reversedNum = 0, remainder, originalNum;

	originalNum = n;
	while (n != 0)
	{
		remainder = n % 10;
		reversedNum = reversedNum * 10 + remainder;
		n /= 10;
	}
	if (originalNum == reversedNum)
		printf("%d is a palindrome.", originalNum);
	else
		printf("%d is not a palindrome.", originalNum);

}
int main()
{
	int n;

	printf("Enter an integer: ");
	scanf_s("%d", &n);

	isPalindrome(n);
		
	getchar();
	return 0;
}