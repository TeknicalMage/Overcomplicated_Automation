#include <iostream>
#include <string>


#include <Windows.h>    

#include <chrono>
#include <thread>
using namespace std;  

int  main()  
{  
string str1 = "/execute in minecraft:overworld run tp @s 1000.30 72.00 1000.30 -8.05 26.22";  
string str2 = " " ;
std::cout << str1 + '\n'; 
str1.replace(0,41,str2);   
std::cout << str1 + '\n';    
}   