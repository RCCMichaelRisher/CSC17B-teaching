/* 
 * Author: Michael Risher
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time Library
#include <iomanip>   //Format Library
#include <fstream>   //File Stream Library
using namespace std;

//User Libraries
#include "Card.hpp"

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void shuffle( Card *deck, int n, int nTimes = 7 );
Card *fillDeck( int n );
void printDeck( Card *deck, int n );
void print( std::ostream &stream, Card *deck, int n );

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand ( time( 0 ) );
    //Declare Variables
    
    Card *deck = fillDeck( Card::NORMAL_DECK_SIZE );
    printDeck( deck, Card::NORMAL_DECK_SIZE );
    shuffle( deck, Card::NORMAL_DECK_SIZE, 7 );
    //Initialize Variables
    
    //Map/Process the Inputs -> Outputs
    
    //Display Inputs/Outputs
    cout << "Shuffled Deck" << endl;
    printDeck( deck, Card::NORMAL_DECK_SIZE );

    ofstream html("output.html");    
    print( html, deck, Card::NORMAL_DECK_SIZE );
    html.close();
    //Clean up memory and files
    delete [] deck;
    //Exit the Program
    return 0;
}

Card *fillDeck( int n ){
  Card *deck = new Card[n];
  for( int i = 0; i < n; i++ ){
    deck[i] = Card( i );
  }
  return deck;
}

void shuffle( Card *deck, int n, int nTimes ){
  for( int times = 0; times < nTimes; times++ ){
    for( int i = 0; i < n; i++ ){
      int r = rand() % n;
      Card temp = deck[i];
      deck[i] = deck[r];
      deck[r] = temp;
    }
  }
}

void printDeck( Card *deck, int n ){
  for( int i = 0; i < 13; i++ ){
    cout
    << setw(20) << deck[i].toString()
    << setw(20) << deck[i + 13].toString()
    << setw(20) << deck[i + 26].toString()
    << setw(20) << deck[i + 39].toString()
    << endl;
  }
}

void print( std::ostream &stream, Card *deck, int n ){
  for( int i = 0; i < n; i++ ){
    stream << deck[i].toHtml() << endl;
  }
}