#ifndef Card_H
#define Card_H

#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
class Card {
    private: 
      int cardNum;
      int faceValue;
      string suit;
      string name;
      string picture;

      void setSuit();
      void setName();
      void setPicture();
    public: 
      static const int NORMAL_DECK_SIZE = 52;
      Card();
      Card( int );
      int getCardNum() const { return cardNum; }
      int getFaceValue() const { return faceValue; }
      string getSuit() const;
      string getName() const;
      string getPicture() const;
      string toString() const;
      string toHtml() const;
};


#endif /* Card_H */