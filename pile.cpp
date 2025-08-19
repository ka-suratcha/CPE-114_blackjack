#include "pile.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// default constructor
Pile::Pile() {
}

// create pile of cards
Pile::Pile(unsigned numberOfCard) {
    for (unsigned i = 0; i < numberOfCard; i++) {
        cards.insert(cards.begin(), Card((i % 13) + 1, i / 13));
    } // insert card(listed) at first position(.begin) of that pile card
}

// insert card at first position
void Pile::insertFirst(Card c) {
    cards.insert(cards.begin(), c);
}

// insert card at specific position
void Pile::insertAt(unsigned position, Card c) { // insert at behind position(array) as parameter
    cards.insert(cards.begin() + position, c);
}

// draw card at first position
Card Pile::drawFirst() {
    if (cards.empty()) throw runtime_error("Deck is empty");                         // draw card at top of deck then return it and remove it form deck
    Card c = cards.front();     // draw at top from deck (reference)
    cards.erase(cards.begin()); // remove from deck
    return c;
}

// draw card at specific position(array) remove it form currentdeck
Card Pile::drawAt(unsigned position) {
    Card c = cards.at(position);           // draw at position as parameter
    cards.erase(cards.begin() + position); // remove from deck
    return c;
}

// draw card and insert to target pile
void Pile::drawAndInsertTo(Pile &targetPile) {
    Card c = cards.front();     // draw at position as parameter from class that call this function
    cards.erase(cards.begin()); // remove

    targetPile.insertFirst(c); // insert at first position of class that is parameter
}

// move card to specific position(array) as parameter
void Pile::local_moveCardTo(unsigned ini, unsigned target) {
    if (ini > target)
        rotate(cards.rend() - ini - 1, cards.rend() - ini, cards.rend() - target);
    else
        rotate(cards.begin() + ini, cards.begin() + ini + 1, cards.begin() + target + 1);
}

// move card to specific position(array) as parameter
void Pile::moveCardTo_thatPile(unsigned ini_position, Pile &target_pile, unsigned target_position) {                              // move card from class that call this function to other class at position as parameter
    if (target_pile.isEmpty()) // if that pile is empty insert at first position
        target_pile.insertFirst(cards.at(ini_position));
    else if (target_position > target_pile.getPileSize()) // if position is more than deck size, insert to last position
        target_pile.insertAt(target_pile.getPileSize(), cards.at(ini_position));
    else // default
        target_pile.insertAt(target_position, cards.at(ini_position));

    cards.erase(cards.begin() + ini_position);
}

// shuffle deck
void Pile::shufflePile() {
    for (unsigned i = 0; i < cards.size(); i++) {
        unsigned x = static_cast<unsigned>(rand()) % cards.size();
        swap(cards.at(x), cards.at(i));
    }
}

// show all cards in the pile
void Pile::showPile() const {
    for (unsigned i = 0; i < cards.size(); i++) {
        (cards.at(i)).showCard();
    }
}

// check if pile is empty
bool Pile::isEmpty() const {return cards.empty();}

// get pile size
unsigned Pile::getPileSize() const { return cards.size(); }

// get card number
unsigned Pile::getNo(unsigned pos) const { return cards.at(pos).getNo(); }

// get card suit
unsigned Pile::getSuit(unsigned pos) const { return cards.at(pos).getSuit(); }