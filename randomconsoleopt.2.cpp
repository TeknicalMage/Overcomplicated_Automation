#include <iostream>
#include <string>

#include <Windows.h>

#include <chrono>
#include <thread>

#include <cstdlib>
//random



using namespace std;

int hits = 0;

void console_splurge(){

    string baz22 [4] = {"/", "#", "'|", "(" }; 


    //int baz [4] {1, 2, 3, 4 };  - universal output 

    int v1 = rand() % 4;  


    std::cout << baz22[v1];


};




void click(){
    while (true){
        Sleep(50);
        if (GetAsyncKeyState(VK_NUMPAD0)) {
            std::cout << hits;
            hits++;
        }
        if (GetAsyncKeyState(VK_NUMPAD3)) {
            //std::cout << "value";
            console_splurge();
            console_splurge();
            console_splurge();
            console_splurge();
            console_splurge();
            console_splurge();
            console_splurge();
            console_splurge();
            console_splurge();
            console_splurge();
            console_splurge();
            console_splurge();
        }
    }
};




int main(){
    click();   
    return 0;





