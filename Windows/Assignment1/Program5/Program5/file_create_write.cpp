/*
Write a program to open an existing file with CreateFile
and use ReadFile to read the contents of file till EOF
and print the contents to console.
HANDLE CreateFileA(
  LPCSTR                lpFileName,
  DWORD                 dwDesiredAccess,
  DWORD                 dwShareMode,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  DWORD                 dwCreationDisposition,
  DWORD                 dwFlagsAndAttributes,
  HANDLE                hTemplateFile
);
BOOL WriteFile(
  HANDLE       hFile,
  LPCVOID      lpBuffer,
  DWORD        nNumberOfBytesToWrite,
  LPDWORD      lpNumberOfBytesWritten,
  LPOVERLAPPED lpOverlapped
);
*/

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<tchar.h>
int _tmain()
{
	HANDLE fileHandle;
	LPCSTR file_name = "output.txt";
	fileHandle = CreateFile(
		file_name,//lpFileName,
		GENERIC_WRITE,//dwShareMode  dwDesiredAccess  write access
		0,//Prevents other processes from opening a file or device if they request delete, read, or write access.
		NULL, //the handle returned by CreateFile cannot be inherited by any child processes
		CREATE_ALWAYS,//create a new file, always  if use create_new then its showing error after compiling once becaz d file is already created
		FILE_ATTRIBUTE_NORMAL,//being the most common default value for files.
		NULL);
	if (fileHandle == INVALID_HANDLE_VALUE)
	{
		printf("\n File can not be opened : %d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("\n File \"%s\" Opened successfully\n", file_name);
	
	/*TCHAR *buffer= (TCHAR*)malloc(sizeof(TCHAR)*100);
	ZeroMemory(buffer,100);
	printf("\n Enter the message to Write:");
	_tscanf_s("%s", buffer,100);*/
	TCHAR buffer[] = TEXT("HELLO CDAC \n Haritha Reddy");
	//writing file
	DWORD numberOfBytesWrite;
	BOOL ret_of_writefile=WriteFile(fileHandle,buffer,sizeof(buffer),&numberOfBytesWrite,NULL);
	if (!ret_of_writefile)
	{
		printf("\n Cannot Write - Error is : %d",GetLastError());
	}
	CloseHandle(fileHandle);
	getchar();
	return 0;
}
