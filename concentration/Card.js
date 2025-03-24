class Card {
  constructor( cardNum) {
    this.cardNum = cardNum
    this.faceValue = cardNum % 13 + 1;
    this.setSuit();
    this.setName();
    this.setPicture();
  }

  setSuit() {
    if (this.cardNum < 13) {
      this.suit = "Hearts";
    } else if (this.cardNum < 26) {
      this.suit = "Diamonds";
    } else if (this.cardNum < 39) {
      this.suit = "Clubs";
    } else {
      this.suit = "Spades";
    }
  }

  setName() {
    switch (this.cardNum % 13) {
      case 12:
        this.name = "King";
        break;
      case 11:
        this.name = "Queen";
        break;
      case 10:
        this.name = "Jack";
        break;
      case 9:
        this.name = "Ten";
        break;
      case 8:
        this.name = "Nine";
        break;
      case 7:
        this.name = "Eight";
        break;
      case 6:
        this.name = "Seven";
        break;
      case 5:
        this.name = "Six";
        break;
      case 4:
        this.name = "Five";
        break;
      case 3:
        this.name = "Four";
        break;
      case 2:
        this.name = "Three";
        break;
      case 1:
        this.name = "Two";
        break;
      case 0:
        this.name = "Ace";
        break;
    }
  }

  setPicture() {
    this.picture = `cards/${this.name.toLowerCase()}${this.suit.toLowerCase()}.jpg`;
  }

  getFaceValue() {
    return this.faceValue;
  }

  getSuit() {
    return this.suit;
  }

  getName() {
    return this.name;
  }

  getPicture() {
    return this.picture;
  }

  getCardNum() {
    return this.cardNum;
  }

  toString() {
    return `${this.name} of ${this.suit}`;
  }

  toHtml() {
    return `<div class='card'>
              <img src='${this.picture}' alt='${this.toString()}'>
              <p>${this.toString()}</p>
              <p>#${this.getCardNum()}</p>
              <p>faceVal: ${this.getFaceValue()}</p>
              <p>Name: ${this.getName()}</p>
            </div>`;
  }
}
