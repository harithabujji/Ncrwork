/*Write a program to print environment variables passed 
to the console application.Also demonstrate the usage of ExpandEnvironmentStrings API.*/
/*
Every process has an environment block that contains a set of environment variables and their values. 
There are two types of environment variables:
user environment variables (set for each user) and 
system environment variables (set for everyone).
GetEnvironmentVariable:function determines whether a specified variable is defined 
in the environment of the calling process, and, if so, what its value is.
SetEnvironmentVariable:function to change an environment variable.
*/

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<tchar.h>
void DumpEnvStrings(PTSTR[]);
int _tmain(int argc, TCHAR *argv[],TCHAR *env[])
{
	DumpEnvStrings(env);
	//system nevironment variables
	TCHAR envVarStrings0[] = TEXT("%USERNAME%");
	TCHAR envVarStrings1[] = TEXT("%USERPROFILE%");

	TCHAR buffer[MAX_PATH];
	DWORD ret;
	//Expands environment-variable strings and replaces them with the values defined for the current user.
	ret = ExpandEnvironmentStrings(envVarStrings0, buffer, MAX_PATH);
	if (!ret)
	{
		printf("Error 0) %d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("\n%s :: %s\n",envVarStrings0 ,buffer);
	ret = ExpandEnvironmentStrings(envVarStrings1, buffer, MAX_PATH);
	if (!ret)
	{
		printf("Error 1) %d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("\n%s :: %s\n", envVarStrings0, buffer);
	getchar();
	return 0;

}
//Prints the environment variables
void DumpEnvStrings(PTSTR pEnvBlock[])
{
	int curr = 0;
	PTSTR *pele = (PTSTR *)pEnvBlock;
	PTSTR pCurrent = NULL;
	while (pele != NULL)
	{
		pCurrent = (PTSTR)(*pele);
		if (pCurrent == NULL)
			pele = NULL;
		else
		{
			_tprintf(TEXT(" [%u] %s\r\n"), curr, pCurrent);
			curr++;
			pele++;
		}


	}

}