<?php

class Card {
  private $cardNum;
  private $faceValue;
  private $suit;
  private $name;
  private $picture;

  public function __construct($cardNum ) {
    $this->cardNum = $cardNum;
    $this->faceValue = $cardNum % 13 + 1;
    $this->setSuit();
    $this->setName();
    $this->setPicture();
  }

  private function setSuit(){
    if( $this->cardNum < 13 ) {
      $this->suit = "Hearts";
    } else if( $this->cardNum < 26 ) {
      $this->suit = "Diamonds";
    } else if( $this->cardNum < 39 ) {
      $this->suit = "Clubs";
    } else {
      $this->suit = "Spades";
    }
  }

  private function setName(){
    switch( $this->cardNum % 13 ) {
      case 12: $this->name = "King"; break;
      case 11: $this->name = "Queen"; break;
      case 10: $this->name = "Jack"; break;
      case 9:  $this->name = "Ten"; break;
      case 8:  $this->name = "Nine"; break;
      case 7:  $this->name = "Eight"; break;
      case 6:  $this->name = "Seven"; break;
      case 5:  $this->name = "Six"; break;
      case 4:  $this->name = "Five"; break;
      case 3:  $this->name = "Four"; break;
      case 2:  $this->name = "Three"; break;
      case 1:  $this->name = "Two"; break;
      case 0:  $this->name = "Ace"; break;
    }
  }

  private function setPicture(){
    $this->picture = "cards/" . strtolower( $this->name ) . strtolower($this->suit) . ".jpg";
  }

  public function getFaceValue() {
    return $this->faceValue;
  }

  public function getSuit() {
    return $this->suit;
  }

  public function getName() {
    return $this->name;
  }

  public function getPicture() {
    return $this->picture;
  }

  public function getCardNum() {
    return $this->cardNum;
  }

  public function toString() {
    return $this->name . " of " . $this->suit;
  }

  public function __toString() {
    return $this->toString();
  }
  public function toHtml(){
    return "<div class='card'>" .
         "<img src='" . $this->picture . "' alt='" . $this->toString() . "'>" .
         "<p>" . $this->toString() . "</p>" .
         "<p>#" . $this->getCardNum() . "</p>" .
         "<p>FaceVal:" . $this->getFaceValue() . "</p>" .
         "<p>name:" . $this->getName() . "</p>" .
         "</div>";
  }
}


?>