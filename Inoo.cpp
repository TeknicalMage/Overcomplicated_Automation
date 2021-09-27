#include <iostream>
#include <string>

#include <Windows.h>

#include <chrono>
#include <thread>




using namespace std;

int hits = 0;

void fuckabout(){
    std::cout << "hit \n\n";
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 };
    key = VkKeyScan(VK_LBUTTON);
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_MOUSE;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    //Moves .210ish blocks per move
    //.57 blocks ish
    int dumbinput = 176.767;

    Sleep(20);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
};


 
void click(){
    while (true){
        Sleep(50);
        if (GetAsyncKeyState(VK_NUMPAD0)) {
            std::cout << hits;
            hits++;
        }
        if (GetAsyncKeyState(VK_NUMPAD2)) { //new version (King Gore)
            fuckabout();
            std::cout << hits;
            hits++;
        }






    }



};

int main(){
    click();   
    return 0;

}



