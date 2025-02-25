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
int *fillArray( int, int );
void clean( int * );
void clean( int **, int );
void printArray( int *arr, int n );
void printArray( int *arr, int n, int perLine );
void printArray( int *arr, int row, int cols, int perLine );
void sortArray( int *arr, int n );
void sortArray( int *arr, int rows, int cols );

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand( time( 0 ) );

    //Declare Variables
    int length;
    int rows;
    int cols;
    int *array1D;
    int *array2D;

    //Initialize Variables
    rows = 10;
    cols = 10;
    length = rows * cols;
    array1D = fillArray( length );
    array2D = fillArray( rows, cols );

    //Map/Process the Inputs -> Outputs
    
    //Display Inputs/Outputs
    cout << "Here is the unsorted 1D array" << endl;
    printArray( array1D, length, 25 );

    sortArray( array1D, length );

    cout << "Here is the sorted 1D array" << endl;
    printArray( array1D, length, 25 );


    cout << "Here is the unsorted 2D array" << endl;
    printArray( array2D, rows, cols, cols );

    sortArray( array2D, rows, cols );

    cout << "Here is the sorted 2D array" << endl;
    printArray( array2D, rows, cols, cols );

    //Clean up memory and files
    clean( array1D );
    clean( array2D );

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

int *fillArray( int row, int col ){
  int *array = new int[row * col];
  for( int i = 0; i < row; i++ ){
    for( int j = 0; j < col; j++ ){
      *(array + i * col + j) = rand() % 90 + 10; 
    }
  }
  return array;
}

void clean( int *arr ){
  delete [] arr;
}

void clean( int **arr, int rows ){
  for( int i = 0; i < rows; i++ ) {
    delete [] arr[i];
  }
  delete [] arr;
}

// step one only make this one then add the perline after
// void printArray( int *arr, int n ){
//   for( int i = 0; i < n; i++ ){
//     cout << arr[i] << " ";
//   }
//   cout << endl;
// }
void printArray( int *arr, int n ){
  printArray( arr, n, n );
}

void printArray( int *arr, int n, int perLine ){
  for( int i = 0; i < n; i++ ){
    cout << arr[i] << " ";
    if( (i+1) % perLine == 0 )
      cout << endl;
  }
  cout << endl;
}

void printArray( int *arr, int row, int cols, int perLine ){
  for( int i = 0; i < row; i++ ){
    for ( int j = 0; j < cols; j++)
    {
      cout << *(arr + i * cols + j) << " ";
    }
    cout << endl;
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

void sortArray( int *arr, int row, int cols ){
  for( int i = 0; i < row; i++ ){
    sortArray( arr + (i * cols), cols );
  }
}