/*
 * File:   main.cpp
 * Author: Michael Risher
 * Created on Feb 17, 2025
 * Purpose:  Dynamic Array Like 2D Structures using structs instead of arrays
 */

// System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>  //Input Output Library
using namespace std;

// User Libraries
struct Array1D {
  int *data;
  int size;
};

struct Array2D {
  int *data;
  int rows;
  int cols;
};

// Global Constants not Variables
// Science, Math, Conversions, Dimensions

// Function Prototypes
Array1D fillArray1D(int);
Array2D fillArray2D(int, int);
void clean(Array1D &);
void clean(Array2D &);
void printArray(const Array1D &, int);
void printArray(const Array2D &, int);
void sortArray(Array1D);
void sortArray(Array2D);

// Execution begins here at main
int main(int argc, char **argv) {
  // Set random number seed
  srand(time(0));

  // Declare Variables
  int length;
  int rows;
  int cols;
  Array1D array1D;
  Array2D array2D;

  // Initialize Variables
  rows = 10;
  cols = 10;
  length = rows * cols;
  array1D = fillArray1D(length);
  array2D = fillArray2D(rows, cols);

  // Map/Process the Inputs -> Outputs

  // Display Inputs/Outputs
  cout << "Here is the unsorted 1D array" << endl;
  printArray(array1D, 25);

  sortArray(array1D);

  cout << "Here is the sorted 1D array" << endl;
  printArray(array1D, 25);

  cout << "Here is the unsorted 2D array" << endl;
  printArray(array2D, cols);

  sortArray(array2D);

  cout << "Here is the sorted 2D array" << endl;
  printArray(array2D, cols);

  // Clean up memory and files
  clean(array1D);
  clean(array2D);

  // Exit the Program
  return 0;
}

Array1D fillArray1D(int n) {
  Array1D arr;
  arr.size = n;
  arr.data = new int[n];
  for (int i = 0; i < n; i++) {
    arr.data[i] = rand() % 90 + 10;
  }
  return arr;
}

Array2D fillArray2D(int row, int col) {
  Array2D arr;
  arr.rows = row;
  arr.cols = col;
  arr.data = new int[row * col];
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      arr.data[i * col + j] = rand() % 90 + 10;
    }
  }
  return arr;
}

void clean(Array1D &arr) { delete[] arr.data; }

void clean(Array2D &arr) { delete[] arr.data; }

void printArray(const Array1D &arr, int perLine) {
  for (int i = 0; i < arr.size; i++) {
    cout << arr.data[i] << " ";
    if ((i + 1) % perLine == 0) cout << endl;
  }
  cout << endl;
}

void printArray(const Array2D &arr, int perLine) {
  for (int i = 0; i < arr.rows; i++) {
    for (int j = 0; j < arr.cols; j++) {
      cout << arr.data[i * arr.cols + j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void sortArray( Array1D arr) {
  for (int i = 0; i < arr.size - 1; i++) {
    for (int j = i + 1; j < arr.size; j++) {
      if (arr.data[i] > arr.data[j]) {
        int temp = arr.data[i];
        arr.data[i] = arr.data[j];
        arr.data[j] = temp;
      }
    }
  }
}

void sortArray( Array2D arr ) {
  for (int i = 0; i < arr.rows; i++) {
    sortArray(Array1D{arr.data + (i * arr.cols), arr.cols});
  }
}