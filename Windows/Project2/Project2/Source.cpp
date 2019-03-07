#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>
const int COUNT = 1000;
int g_nsum = 0;
//struct _DATA
//{
//
//};
CRITICAL_SECTION g_cs;

DWORD WINAPI FirstThread(LPVOID lparam)
{
	EnterCriticalSection(&g_cs);
	g_nsum = 0;
	for (int i = 1; i <= COUNT; i++)
	{
		g_nsum += i;
	}
	LeaveCriticalSection(&g_cs);
	return g_nsum;
}
int main()
{
	DWORD dwthID1, dwthID2,lpExitcode1,lpExitCode2;
	HANDLE hthread1, hthread2,arry_hand[2];
	InitializeCriticalSection(&g_cs);
	//InitializeCriticalSectionAndSpinCount(&g_cs, 4000);
	hthread1 = CreateThread(NULL,//default security
		0,//default stack size
		FirstThread,//call back func
		NULL,//parameter to thread func
		0,//creation flags
		&dwthID1//id
	);

	if (NULL == hthread1)
	{
		printf("unable to create : %d\n", GetLastError());
		getchar();
		return FALSE;
	}
	printf("%d\n", g_nsum);
	hthread2 = CreateThread(NULL,//default security
		0,//default stack size
		FirstThread,//call back func
		NULL,//parameter to thread func
		0,//creation flags 0)	The thread runs immediately after creation. CREATE_SUSPENDED) The thread is created in a suspended state, and does not run until the ResumeThread function is called.
		//STACK_SIZE_PARAM_IS_A_RESERVATION) The dwStackSize parameter specifies the initial reserve size of the stack. If this flag is not specified, dwStackSize specifies the commit size.
		&dwthID1//id
	);
	if (NULL == hthread2)
	{
		printf("unable to create : %d\n", GetLastError());
		getchar();
		return FALSE;
	}
	printf("%d", g_nsum);

	CloseHandle(hthread1);
	CloseHandle(hthread2);
	system("pause");
	return 0;
}