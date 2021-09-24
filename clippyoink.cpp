#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main ()
{
	OpenClipboard(0);
	const char* op = "How Are You?";
	const size_t ln = strlen(op) + 1;
	HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, ln);
	memcpy(GlobalLock(h), op, ln);
	GlobalUnlock(h);
	CloseClipboard();
	//getch();
    system("cls");
    OpenClipboard(0);
    HANDLE in = GetClipboardData(CF_TEXT); //There are many other formats
    cout<<(char*)in<<endl;
    CloseClipboard();
	
}
