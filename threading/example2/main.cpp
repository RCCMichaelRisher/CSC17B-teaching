/* 
 * Author: Michael Risher
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <thread>
#include <bits/stdc++.h>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main

void func(){
    cout << "Hello from the thread" << endl;
}
int main(int argc, char** argv) {
    
    //create the thread
    thread t( func );

    t.join();
    cout << "main thread finished" << endl;
    return 0;
}