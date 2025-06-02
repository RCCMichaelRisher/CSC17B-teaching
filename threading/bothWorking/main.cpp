/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Michael.Risher
 *
 * Created on June 2, 2025, 9:16 AM
 */

 #include <iostream>
 #include <thread>
 #include <chrono>
 #include <mutex>
 #include <bits/stdc++.h>
 
 using namespace std;
 
 //mutex coutMutex;
 
 void printMsg( int s ){
     for( int i = s; i > 0; i-- ){
         //lock_guard<mutex> lock( coutMutex );
         cout << "thread " << i << "\n";
         this_thread::sleep_for( chrono::milliseconds( 500 ) );
     }
 }
 
 
 int main(int argc, char** argv) {
     int l = 5;
     cout << "starting the thread" << endl;
     //start a new thread
     thread t( printMsg, l );
     
     for( int i = 0; i < l; i++ ){
         //lock_guard<mutex> lock( coutMutex );
         cout << "main: " << i << "\n";
         this_thread::sleep_for( chrono::milliseconds( 500 ) );
     }
     
     //wait for the threads to finish
     t.join();
     //detachs the thread and lets it run independently
    //  t.detach();
     cout << "main is done"<< endl;
     return 0;
 }
 
 