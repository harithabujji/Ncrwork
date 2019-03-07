/*Implement a program where command line arguments passed to program are read 
via GetCommandLine and converted to argv style by CommandLineToArgvW.*/

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	LPWSTR *ArgList;
	int i;
	//GetCommandLineW() returns a ptr to command line args
	//CommandLineToArgvW returns the address of the first element
	ArgList = CommandLineToArgvW(GetCommandLineW(), &argc);
	if (NULL == ArgList)
	{
		wprintf(L"no command line arguments");
		return 0;
	}
	else
	{
		for (i = 0; i < argc; i++)
		{
			printf("%d : %lS", i, ArgList[i]);
			printf("\n");
		}
	}
	// Free memory allocated for CommandLineToArgvW arguments.
	LocalFree(ArgList);
	getchar();
}