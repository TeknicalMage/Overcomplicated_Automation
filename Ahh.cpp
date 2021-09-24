#include <iostream>
#include <string>

#include <Windows.h>

#include <chrono>
#include <thread>

#include <cstdlib>
//random    

int currentxcor = 0;

using namespace std;
 POINT point;

int hits = 0;

void console_splurge(){

    string baz22 [4] = {"/", "#", "'|", "(" }; 
    //int baz [4] {1, 2, 3, 4 };  - universal output 
    int v1 = rand() % 4;  
    std::cout << baz22[v1];


};

void Forwardmove(){
    currentxcor = currentxcor+1;
    std::cout << currentxcor;
    std::cout << "\n\n";
};

void Backwardmove(){
    currentxcor = currentxcor-1;
    std::cout << currentxcor;
    std::cout << "\n\n";
};

void mouseright(){
    if (GetCursorPos(&point)) {
        //cout << point.x << "," << point.y << "\n";
        std::cout << " right 50 px \n\n";
        SetCursorPos(point.x + 50,point.y);
    }
}; 

void mouseleft(){
    if (GetCursorPos(&point)) {
        //cout << point.x << "," << point.y << "\n";
        std::cout << " left 50 px \n\n";
        SetCursorPos(point.x - 50,point.y);
    }
}; 

void mouseup(){
    if (GetCursorPos(&point)) {
        //cout << point.x << "," << point.y << "\n";
        std::cout << " plus 50 px on y axis \n\n";
        SetCursorPos(point.x,point.y + 50);
    }
}; 

void mousedown(){
    if (GetCursorPos(&point)) {
        //cout << point.x << "," << point.y << "\n";
        std::cout << " minus 50 px on y axis \n\n";
        SetCursorPos(point.x,point.y - 50);
    }
}; 


//Notes of Sorts
//---------- (ThreadName).join = wait for thread to finish
//---------- (ThreadName).detach = Creates a daemon process - thread will run independent till complete


void click(){
    while (true){
        Sleep(50);
        if (GetAsyncKeyState('W')) {
            std::thread a1(Forwardmove);
            a1.detach();

            //std::cout << hits;
            //hits++;
        }
        if (GetAsyncKeyState('S')) {
            std::thread a2(Backwardmove);
            a2.detach();


        }
        //Left Mouse move
        if (GetAsyncKeyState(VK_NUMPAD4)) {
            std::thread a3(mouseleft);
            a3.detach();


        }
        //Right Mouse move
        if (GetAsyncKeyState(VK_NUMPAD6)) {
            std::thread a4(mouseright);
            a4.detach();


        }
        if (GetAsyncKeyState(VK_NUMPAD8)) {
            std::thread a5(mousedown);
            a5.detach();


        }
        if (GetAsyncKeyState(VK_NUMPAD2)) {
            std::thread a6(mouseup);
            a6.detach();


        }
    }
};




int main(){
    click();   
    return 0;


}