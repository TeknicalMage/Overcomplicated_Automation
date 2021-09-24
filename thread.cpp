#include <iostream>
#include <string>

#include <Windows.h>

#include <chrono>
#include <thread>

#include <cstdlib>
//random    



using namespace std;
 POINT point;

int hits = 0;

void console_splurge(){

    string baz22 [4] = {"/", "#", "'|", "(" }; 
    //int baz [4] {1, 2, 3, 4 };  - universal output 
    int v1 = rand() % 4;  
    std::cout << baz22[v1];


};

void hit42(){
    std::cout << "Test";
};

void mousechk(){
    if (GetCursorPos(&point)) {
        cout << point.x << "," << point.y << "\n";
    }
};


//Notes of Sorts
//---------- (ThreadName).join = wait for thread to finish
//---------- (ThreadName).detach = Creates a daemon process - thread will run independent till complete


void click(){
    while (true){
        Sleep(50);
        if (GetAsyncKeyState(VK_NUMPAD0)) {
            std::thread a1(hit42);
            a1.detach();

            //std::cout << hits;
            //hits++;
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
        if (GetAsyncKeyState(VK_NUMPAD1)) {
            std::thread Sesh(mousechk);
            //cout << (Sesh.get_id());
            Sesh.detach();


        }
    }
};




int main(){
    click();   
    return 0;


}