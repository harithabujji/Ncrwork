/*
Write a program which uses the CreateProcess API to create two child processes (say calc.exe and notepad.exe).
Print HANDLE value and process ID of each child process.

BOOL CreateProcessA(
  LPCSTR                lpApplicationName,
  LPSTR                 lpCommandLine,
  LPSECURITY_ATTRIBUTES lpProcessAttributes,
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  BOOL                  bInheritHandles,
  DWORD                 dwCreationFlags,
  LPVOID                lpEnvironment,
  LPCSTR                lpCurrentDirectory,
  LPSTARTUPINFOA        lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
);

*/

#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

void _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si1,si2;
	PROCESS_INFORMATION pi1,pi2;

	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));

	ZeroMemory(&si2, sizeof(si2));
	si2.cb = sizeof(si2);
	ZeroMemory(&pi2, sizeof(pi2));

	if (argc != 3)
	{
		printf("Usage: %s [cmdline]\n", argv[0]);
		system("pause");
		return;
	}

	// Start the child process. 
	if (!CreateProcess(NULL,   // No module name (use command line)
		argv[1],        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si1,            // Pointer to STARTUPINFO structure
		&pi1)           // Pointer to PROCESS_INFORMATION structure
		)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		system("pause");
		return;
	}

	//second child process
	if (!CreateProcess(NULL,   // No module name (use command line)
		argv[2],        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si2,            // Pointer to STARTUPINFO structure
		&pi2)           // Pointer to PROCESS_INFORMATION structure
		)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		system("pause");
		return;
	}

	//printing proceess ids and handle
	printf("Handle of first process is %ld \n", pi1.hProcess);
	printf("Process id of first process is %ld \n", pi1.dwProcessId);
	printf("primary thread id of first procezs is %ld\n", pi1.dwThreadId);

	printf("Handle of second process is %ld \n", pi2.hProcess);
	printf("Process id of second process is %ld \n", pi2.dwProcessId);
	printf("primary thread id of second procezs is %ld\n", pi2.dwThreadId);

	// Wait until child process exits.
	WaitForSingleObject(pi1.hProcess, INFINITE);
	WaitForSingleObject(pi2.hProcess, INFINITE);

	

	// Close process and thread handles. 
	CloseHandle(pi1.hProcess);
	CloseHandle(pi1.hThread);
	CloseHandle(pi2.hProcess);
	CloseHandle(pi2.hThread);
	system("pause");
	return;
}