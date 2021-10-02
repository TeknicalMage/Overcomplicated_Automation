#include <iostream>
#include <string>


#include <Windows.h>    

#include <chrono>
#include <thread>






using namespace std;

int hits = 0;


    //C Keypress
void C_Key_input(){
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 };
    key = VkKeyScan('c');
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(20);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
    //C Keypress
};

    //F3 Keypress
void F3_Key_input(){
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 }; 
    key = (VK_F3);
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    C_Key_input();
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
    //F3 Keypress
};

    //Move Forward Input
void fuckaboutforward(){
    std::cout << "Move Forward \n\n";
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 };
    key = VkKeyScan('w'); 
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    //Keydown time determines Distance
    //std::this_thread::sleep_for(std::chrono::milliseconds(339213));

    //std::this_thread::sleep_for(std::chrono::milliseconds(11940)); | 51.587
    //std::this_thread::sleep_for(std::chrono::milliseconds(11540)); | 49.86
    //std::this_thread::sleep_for(std::chrono::milliseconds(11640)); | 50.291
    //std::this_thread::sleep_for(std::chrono::milliseconds(11600)); | 50.076 per input
    std::this_thread::sleep_for(std::chrono::milliseconds(11600000));
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
};
    //Move Forward Input        


string Coord_Rip (){
	OpenClipboard(0);
	const char* op = "Where in tf am I";
	const size_t ln = strlen(op) + 1;
	HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, ln);
	memcpy(GlobalLock(h), op, ln);
	GlobalUnlock(h); 
	CloseClipboard();
    system("cls");
    OpenClipboard(0);
    HANDLE in = GetClipboardData(CF_TEXT); //There are many other formats
	string value = (char*)in;
    CloseClipboard();
    string str2 = " " ;
    //std::cout << value + '\n'; 
    value.replace(0,41,str2);   
    //std::cout << value + '\n';  
    //test values and whatnot
	return value;
 
};

void loc_detect(){
    while(true){
        //F3 + C -- The Keyboard shortcut to show coords
        F3_Key_input();
        cout << Coord_Rip();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        //Side notee. Sleep is in Mili seconds
    }
}


 
void tick(){
    while (true){
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        if (GetAsyncKeyState(VK_NUMPAD0)) {
            std::cout << hits;
            hits++;
        }
        if (GetAsyncKeyState(VK_NUMPAD2)) { 
            std::thread forwardm(fuckaboutforward);
            forwardm.detach();
            std::cout << hits;
            hits++;
        }
        if (GetAsyncKeyState(VK_NUMPAD1)) { 
            std::thread whereami(loc_detect);
            whereami.detach();
            std::this_thread::sleep_for(std::chrono::milliseconds(20)); 
        }






    }



};

int main(){
    std::cout << "Script Start\n\n";
    tick();   
    return 0;

}



