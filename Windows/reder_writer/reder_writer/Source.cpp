#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>

DWORD WINAPI thread_func(LPVOID lparam)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d \n", i);
		Sleep(1000);
	}
	return 0;
}

int main()
{
	DWORD dwthID1, dwthID2,dwThreadId;
	HANDLE hthread1, hthread2;


	hthread1 = CreateThread(NULL,//default security
		0,//default stack size
		thread_func,//call back func
		NULL,//parameter to thread func
		0,//creation flags 0)	The thread runs immediately after creation. CREATE_SUSPENDED) The thread is created in a suspended state, and does not run until the ResumeThread function is called.
		//STACK_SIZE_PARAM_IS_A_RESERVATION) The dwStackSize parameter specifies the initial reserve size of the stack. If this flag is not specified, dwStackSize specifies the commit size.
		&dwthID1//id
	);

	if (NULL == hthread1)
	{
		printf("unable to create : %d\n", GetLastError());
		getchar();
		return FALSE;
	}
	hthread2 = CreateThread(NULL,//default security
		0,//default stack size
		thread_func,//call back func
		NULL,//parameter to thread func
		CREATE_SUSPENDED,//creation flags 0)	The thread runs immediately after creation.
		&dwthID1//id
	);
	if (NULL == hthread2)
	{
		printf("unable to create : %d\n", GetLastError());
		getchar();
		return FALSE;
	}
	CloseHandle(hthread1);
	CloseHandle(hthread2);
	system("pause");
	return 0;
}