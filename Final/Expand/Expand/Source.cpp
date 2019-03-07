#include<string.h>
#include<iostream>
#define MAX 128
using namespace std;
//expand string function
void expand_string(char *input)
{
	char *output = new char[MAX];
	int i = 0, j = 0;
	int asci_char;
	int l = strlen(input);
	//input should not contain - at front or back
	if (input[0] == '-' || input[l - 1] == '-')
		throw "input should not contain hyphen at front or back";
	//traversing through string
	while ((asci_char = input[i++]) != '\0')
	{
		// if hyphen is betweeen two same characters
		if (input[i] == '-'&&input[i + 1] == asci_char)
		{
			output[j++] = asci_char;
			i = i + 2;

		}
		//if hyphen is between upper n lower asciiss like a-0
		else if (input[i] == '-'&&input[i + 1] < asci_char)
			throw "invalid expression";
		else if (input[i] == '-'&&input[i + 1] > asci_char)
		{
			i++;
			while (asci_char < input[i])
			{
				output[j++] = asci_char++;
			}
		}
		// if input have two hyphens continuously
		else if (input[i] == '-'&&input[i + 1] == '-')
		{
			throw "input should not have two hyphens continuously";
		}
		else
			output[j++] = asci_char;
	}
	output[j] = '\0';
	cout << "Expanded string is:" << endl;
	cout << output;
	delete[] output;
}
int main()
{
	char *input = new char[MAX];
	//try block
	try
	{
		cout << "Enter string :" << endl;
		cin >> input;
		expand_string(input);		
		delete[] input;
	}
	//catch block
	catch (const char*msg)
	{
		cout << msg<<endl;
		delete[] input;
	}
	cout << "\n";
	system("pause");
	return 0;
}