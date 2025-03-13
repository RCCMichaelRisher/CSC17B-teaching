#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, Setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std;  //Libraries compiled under std


#include "CMovie.hpp"

CMovie::CMovie(){
    
    //I copied the output from Code-E so I wouldn't make any typing mistakes
    //Then I just formatted.
    cout <<"This program reviews structures" << endl;
    cout <<"Input how many movies, the Title of the Movie, Director, Year "<<
          "Released, and the Running Time in (minutes)." << endl;
    cin >> this->nMovies;                //Integer Read
    //Declare the Structure array
    movies = new MovieInfo[nMovies];   //dynamic Array


    //Now you can loop on the data as many times as it takes!
    for(int i = 0; i < nMovies; i++){
        cin.ignore();              //Oh Yea, Gotta do this for the buffer
        cout << "Title: ";
        getline( cin, movies[i].title );//Movie Name In an Array Structure
        int size=81;//Make it Dynamic
        movies[i].director = new char[size];
        cout << "Director: ";
        cin.getline( movies[i].director, size - 1 );//Array Structure element
        cout << "Year: ";
        cin >> movies[i].year;//Look ma, no ignore after gets!!!!
        cout << "Length: ";
        cin >> movies[i].runtime;//Look again,no ignore after gets,only before
    }
}

CMovie::CMovie(const CMovie &){ //copy constructor
    //TODO you can fill this up
}

CMovie CMovie::operator=(const CMovie &obj){
    //todo you can fill this up
}

CMovie::~CMovie(){
    //Clean Up the Dynamic Stuff
    delete [] movies;
}

void CMovie::display(){
    //Now you can loop on the data as many times as it takes!
    for(int i = 0; i < nMovies; i++){
        cout << left << endl;
        cout << setw(11) << "Title:" << movies[i].title << endl;
        cout << setw(11) << "Director:" << movies[i].director << endl;
        cout << setw(11) << "Year:" << movies[i].year << endl;
        cout << setw(11) << "Length:" << movies[i].runtime << endl;
    } 
}