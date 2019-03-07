#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<tchar.h>
int main()
{
	char ch = 'A';
	wchar_t wch = L'B';
	WCHAR wchm = L'A';
	TCHAR tc = TEXT('C');
	printf("\ncharacter is :%c", ch);
	printf("\nwide character is %C", wch);
	printf("\ntext char is %c", tc);
	printf("\nSize of char : %d \nSize of Wchar : %d\n", sizeof(ch), sizeof(wch));
	WCHAR wide_array[] = L"hello";
	char ch_array[] = "hello";
	printf("\ncharcter ansi array is %s",ch_array);
	printf("\ncharacter wide array is %S", wide_array);
	//WideCharToMultiByte(CP_UTF8, 0, wide_array, -1,NULL, 0, NULL, NULL);
	int res;
	res = IsTextUnicode(ch_array, strlen(ch_array), NULL);
	if (res == 0)
	{
		printf("\nch_array is not unicode");
	}
	else
	{
		_tprintf(_T("\nch_array is unicode"));
	}
	res = IsTextUnicode(wide_array, wcslen(wide_array), NULL);
	if (res == 0)
	{
		printf("\nwide_array is not unicode");
	}
	else
	{
		printf("\nwide_array is unicode");
	}
	int size;
	size = MultiByteToWideChar(CP_UTF8, 0, ch_array, -1, NULL, 0);
	if (size == 0)
	{
		printf("\nthe error occured is %d", GetLastError());
	}
	else
		printf("\nsize of ch_array is %d", size);
	WCHAR *ansitowide = new WCHAR[size];
	size = MultiByteToWideChar(CP_UTF8, 0, ch_array, -1, ansitowide, size);
	if (size == 0)
	{
		printf("\nthe error occured is %d", GetLastError());
		return 0;
	}
	else
		printf("\nthe ansitowide contains %S", ansitowide);
	size = WideCharToMultiByte(CP_UTF8, 0, wide_array, -1, NULL, 0, NULL, NULL);
	if (size == 0)
	{
		printf("\nthe error occured is %d", GetLastError());
		return 0;
	}
	else
		printf("\nsize of ch_array is %d", size);

	CHAR *widetoansi = new CHAR[size];
	size = WideCharToMultiByte(CP_UTF8, 0, wide_array, -1, widetoansi, size, NULL, NULL);
	if (size == 0)
	{
		printf("\nthe error occured is %d", GetLastError());
	}
	else
		printf("\nthe widetoansi contains %s", widetoansi);
	delete(ansitowide);
	delete(widetoansi);
	getchar();
    system(" pause ");
	return 0;
}