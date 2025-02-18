/* 
 * File:   main.cpp
 * Author: Michael Risher
 * Created on Feb 17, 2025
 * Purpose:  Template to be used for all
 *           future Hmwk, Labs, Exams, Projects
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
int *fillArray( int );
void clean( int * );
void printArray( int *arr, int n );
void sortArray( int *arr, int n );

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand( time( 0 ) );

    //Declare Variables
    int length;
    int *array;

    //Initialize Variables
    length = 100;
    array = fillArray( length );

    //Map/Process the Inputs -> Outputs
    
    //Display Inputs/Outputs
    printArray( array, length );

    sortArray( array, length );

    printArray( array, length );
    //Clean up memory and files
    clean( array );

    //Exit the Program
    return 0;
}

int *fillArray( int n ){
  int *arr = new int[n];
  for( int i = 0; i < n; i++ ){
    arr[i] = rand() % 90 + 10;
  }
  return arr;
}

void clean( int *arr ){
  delete [] arr;
}

void printArray( int *arr, int n ){
  cout << endl;
  for( int i = 0; i < n; i++ ){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void sortArray( int *arr, int n ){
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if( arr[i] > arr[j] ){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}