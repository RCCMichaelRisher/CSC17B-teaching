/* 
 * Author: Michael Risher
 * Purpose: Program to perform matrix multiplication on square matrices using 2d arrays simulated like 1d arrays
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>   //Format Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time Library

using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
int *fillMat(int); //fill a matrix with random numbers
int *matrixMult(int *, int *, int); //matrix multiplication
void printMat(int *, int, bool = true); //print a 
void destroy(int *); //deallocate memory for a matrix

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand( time( 0 ) );

    //Declare Variables
    int *matA; //matrix A
    int *matB; //matrix B
    int *matResult; //matrix result

    int dim; //dimension of square matrices
    bool isPretty = true; //pretty print the matrix

    //Initialize Variables
    //get the dimension of the square matrices
    cout << "Enter the dimension of the square matrices: ";
    cin >> dim;

    //allocate memory for the matrices
    matA = fillMat( dim );
    matB = fillMat( dim );

    //get the values for the matrices
    //Map/Process the Inputs -> Outputs
    
    matResult = matrixMult( matA, matB, dim );
    isPretty = ( dim > 25 ) ? false : true;
    //Display Inputs/Outputs
    
    cout << "Matrix A:" << endl;
    printMat( matA, dim, isPretty );
    cout << "Matrix B:" << endl;
    printMat( matB, dim, isPretty );

    cout << "Matrix Result:" << endl;
    printMat( matResult, dim, isPretty );

    //Clean up memory and files
    //deallocate memory for the matrices
    destroy( matA ); 
    destroy( matB );
    destroy( matResult );
    //Exit the Program
    return 0;
}


/**
 * destroy
 * Deallocate memory for a matrix
 * @param mat - the matrix to deallocate
 */
void destroy( int *mat ){
    delete [] mat;
}

/**
 * fillMat
 * Fills a matrix with random numbers between 10 and 99
 * @param dim - the dimension of the square matrix
 * @return - a pointer to the matrix
 */
int *fillMat( int dim ){
    int *mat = new int[dim * dim];
    int n = dim * dim;
    for( int i = 0; i < n; i++ ){
        mat[i] = rand() % 9 + 1; //random number between 1 and 10
    }
    return mat;

}

/**
 * matrixMult
 * Multiply two square matrices
 * @param matA - matrix A
 * @param matB - matrix B
 * @param dim - the dimension of the square matrices
 * @return - a pointer to the result matrix
 */
int *matrixMult( int *matA, int *matB, int dim ){
    // 1 2    4 5
    // 3 4    6 7
    //resulting matrix is
    // 1*4 + 2*6  1*5 + 2*7
    // 3*4 + 4*6  3*5 + 4*7

    int *matResult = new int[dim * dim];

    for( int i = 0; i < dim; i++ ){  //i is the row of matA and the row of matResult
        for( int j = 0; j < dim; j++ ){ //j is the column of matB and the column of matResult
            matResult[i * dim + j] = 0; //initialize the value to 0
            for( int k = 0; k < dim; k++ ){ //k is the column of matA and the row of matB
                //multiply the row of matA by the column of matB
                matResult[i * dim + j] += matA[i * dim + k] * matB[k * dim + j]; 
            }
        }
    }

    return matResult;
}

/**
 * printMat
 * Print a matrix
 * @param mat - the matrix to print
 * @param dim - the dimension of the square matrix
 */
void printMat( int *mat, int dim, bool pretty ){
    for( int i = 0; i < dim; i++ ){
        cout << "| ";
        
        //loop through the columns
        for( int j = 0; j < dim; j++ ){
            if( pretty) 
                cout << setw( dim ) << mat[i * dim + j] << " ";
            else
                cout << mat[i * dim + j] << " ";
        }
        cout << " |" << endl;
    }
}

