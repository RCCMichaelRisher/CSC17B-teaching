#ifndef CMovie_H
#define CMovie_H

#include "MovieInfo.hpp"

using namespace std;

class CMovie {
    private: 
        MovieInfo *movies;//Pointer to the dynamic Movie structure.
        int nMovies;//Number of movies in the structure.
    public: 
        CMovie();//Constructor
        CMovie(const CMovie &);//Copy Constructor
        CMovie operator=(const CMovie &);//Chain Equality Operator
        ~CMovie();//Destructor
        void display();//Display
        int getNMovies() const { return nMovies; }//Get the number of movies
        void setNMovies(int n) { nMovies = n; }//Set the number of movies
      
};


#endif /* CMovie_H */