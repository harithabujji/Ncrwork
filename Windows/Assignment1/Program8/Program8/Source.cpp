
/*
Create a named event object with CreateEvent. 
Verify the presence of the created event with WinObj (Hint: Run WinObj as Administrator and 
Look for event in path similar to:Sessions BaseNamedObjects. can be integer).
Also verify how kernel object is deleted when no longer used.

HANDLE CreateEventA(
  LPSECURITY_ATTRIBUTES lpEventAttributes,
  BOOL                  bManualReset,// If this parameter is FALSE, the function creates an auto-reset event object, 
  BOOL                  bInitialState,//If this parameter is TRUE, the initial state of the event object is signaled; otherwise, it is nonsignaled.
  LPCSTR                lpName //If lpName is NULL, the event object is created without a name.
);

*/
#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<windows.h>

int main()
{
	HANDLE g_hEvent = CreateEvent(NULL, FALSE, FALSE, TEXT("namedevent"));
	if (g_hEvent == NULL)
	{
		printf("Unable to create or open a event object : (%d) \n", GetLastError());
		system("pause");
		return 0;
	}
	system("pause");
	CloseHandle(g_hEvent);
	return 1;
}