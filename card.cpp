#include "card.h"

using namespace std;

// default constructor
Card::Card() {
    no = 0;
    suit = 0;
}

// parameterized constructor
Card::Card(unsigned n, unsigned s) {
    no = n;
    suit = s;
}

// set card number
void Card::setNo(unsigned n) { no = n; }

// set card suit
void Card::setSuit(unsigned s) { suit = s; }

// get card number
unsigned Card::getNo() const { return no; }

// get card suit
unsigned Card::getSuit() const { return suit; }

// show card
void Card::showCard() const {
    switch (getNo()) {
        case 1: cout << "A"; break;
        case 11: cout << "J"; break;
        case 12: cout << "Q"; break;
        case 13: cout << "K"; break;
        default: cout << getNo();
    }
    cout << ' ';

    switch (getSuit()) {
        case 0: cout << "Club"; break;
        case 1: cout << "Diamond"; break;
        case 2: cout << "Heart"; break;
        case 3: cout << "Spade"; break;
        default: cout << "Error";
    }
    cout << endl;
}