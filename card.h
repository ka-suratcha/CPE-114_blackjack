#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
public:
    // constructors
    Card();
    Card(unsigned n, unsigned s);

    // setters
    void setNo(unsigned n);
    void setSuit(unsigned s);

    // getters
    unsigned getNo() const;
    unsigned getSuit() const;

    // function
    void showCard() const;

private:
    unsigned no{};      // card number
    unsigned suit{};    // card suit
};

#endif
