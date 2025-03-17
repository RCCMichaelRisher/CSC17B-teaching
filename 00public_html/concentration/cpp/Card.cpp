#include "Card.hpp"
#include <algorithm>

Card::Card() {
  cardNum = -1;
  faceValue = -1;
  suit = "Null";
  name = "Null";
  picture = "Null";
}

Card::Card( int val ){
  cardNum = val;
  faceValue = val % 13 + 1;
  setSuit();
  setName();
  setPicture();
}

void Card::setSuit() {
  if( cardNum < 13 ) {
    suit = "Hearts";
  } else if( cardNum < 26 ) {
    suit = "Diamonds";
  } else if( cardNum < 39 ) {
    suit = "Clubs";
  } else {
    suit = "Spades";
  }
}

void Card::setName(){
  switch( cardNum % 13 ) {
    case 12: name = "King"; break;
    case 11: name = "Queen"; break;
    case 10: name = "Jack"; break;
    case 9: name = "Ten"; break;
    case 8: name = "Nine"; break;
    case 7: name = "Eight"; break;
    case 6: name = "Seven"; break;
    case 5: name = "Six"; break;
    case 4: name = "Five"; break;
    case 3: name = "Four"; break;
    case 2: name = "Three"; break;
    case 1: name = "Two"; break;
    case 0: name = "Ace"; break;
    default: name = to_string(cardNum % 13 + 1); break;
  }
}


char helpLower(char c) {
  return std::tolower(c);
}

void Card::setPicture() {
  string n = name;
  transform(n.begin(), n.end(), n.begin(), &helpLower );
  string s = suit;

  //using a lambda function to convert to lowercase
  //[] capture clause blank means we are not using any variables from the surrounding scope
  //-> char means the return type of the lambda function is char
  //transform takes a range and applies a function to each element in the range
  transform(s.begin(), s.end(), s.begin(), [](char c) -> char { return std::tolower(c); });
  picture = "cards/" + n + s + ".jpg";
}

string Card::getSuit() const {
  return suit;
}
string Card::getName() const {
  return name;
}

string Card::getPicture() const {
  return picture;
}

string Card::toString() const {
  return name + " of " + suit;
}

string Card::toHtml() const {
  stringstream ss;
  ss << "<div class=\"card\">"
     << "<img src=\"" << picture << "\" alt=\"" << toString() << "\">"
     << "<p>" << toString() << "</p>"
     << "</div>";
  return ss.str();
}