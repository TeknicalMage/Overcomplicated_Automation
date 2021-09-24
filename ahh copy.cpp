#include <iostream>
#include <string>

#include <Windows.h>

#include <chrono>
#include <thread>


using namespace std;

void query(){

    std::cout << "Type how many movements of the mouse you want";
    
    int x;

    string y = "lmao";

    std::cin >> x;

    std:cout << "\n" + y;

}

void screen(){
    std::this_thread::sleep_for(std::chrono::seconds(5));
    SetCursorPos(200, 200);

    int val = 1;

    while (val = 1){
        POINT point;
        if (GetCursorPos(&point)) {
            cout << point.x << "," << point.y << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
} 
    };

    





}

int main(){
    query();    
    screen();
    return 0;

}



