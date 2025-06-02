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
 #include <bits/stdc++.h>
 
 using namespace std;
 
 void printMsg( string msg ){
     cout << "Msg from main " << msg << endl; 
 }
 
 void printMsgRef( string &msg ){
     cout << "Msg from main " << msg << endl; 
 }
 
 int main(int argc, char** argv) {
     string msg = "Hi thread ref";
     
     cout << "starting the thread" << endl;
     //start a new thread
     thread t( printMsg, "hi Thread" );
     thread t2( printMsgRef, ref( msg ) );
     
     //wait for the threads to finish
     t.join();
     t2.join();
     cout << "main is done"<< endl;
     return 0;
 }
 
 