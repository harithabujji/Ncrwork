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
BOOL ReadFile(
  HANDLE       hFile,
  LPVOID       lpBuffer,
  DWORD        nNumberOfBytesToRead,
  LPDWORD      lpNumberOfBytesRead,
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
	LPCSTR file_name = "input.txt";
	fileHandle = CreateFile(
		file_name,//lpFileName,
		GENERIC_READ,//dwShareMode  dwDesiredAccess  Read access
		0,//Prevents other processes from opening a file or device if they request delete, read, or write access.
		NULL, //the handle returned by CreateFile cannot be inherited by any child processes
		OPEN_EXISTING,//Opens a file, always.
		FILE_ATTRIBUTE_NORMAL,//being the most common default value for files.
		NULL);
	if (fileHandle == INVALID_HANDLE_VALUE)
	{
		printf("\n File can not be opened : %d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("\n File %s Opened successfully",file_name);

	//File Size
	DWORD SIZE= GetFileSize(fileHandle,NULL);
	printf("\n Size of file is : %d",SIZE);
	//reading file

	DWORD numberOfBytesRead;
	TCHAR *buffer=(TCHAR*)malloc((SIZE)*sizeof(TCHAR));
	BOOL ret_of_readfile;
	//while (1)
	//{
		ZeroMemory(buffer, SIZE);
		ret_of_readfile = ReadFile(fileHandle, buffer, (SIZE), &numberOfBytesRead, NULL);
		if (ret_of_readfile&&numberOfBytesRead==0)
		{
			printf("\n End Of File");
			CloseHandle(fileHandle);
			//break;
				return 0;
		}
		else
		{
			printf("\n Number of bytes read :%d", numberOfBytesRead);
			buffer[SIZE] = '\0';

			printf("\n File Contents : \n%s", buffer);
		}
	//}
	CloseHandle(fileHandle);
	getchar();
	return 0;
}
