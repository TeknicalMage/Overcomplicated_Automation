#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

string value22 ()
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
	string value = (char*)in;
    //cout<<(char*)in<<endl;
	//cout << value;
    CloseClipboard();
	return value;
 
};

int main(){
    cout << value22();   
    return 0;


}