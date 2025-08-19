#ifndef PILE_H
#define PILE_H
#include "card.h"
#include <vector>

class Pile
{
public:
    // constructors
    Pile();
    explicit Pile(unsigned numberOfCards);

    // insert card
    void insertFirst(Card);
    void insertAt(unsigned, Card);

    // draw card
    Card drawFirst();
    Card drawAt(unsigned);
    void drawAndInsertTo(Pile&);

    // move card
    void local_moveCardTo(unsigned, unsigned);
    void moveCardTo_thatPile(unsigned, Pile&, unsigned);

    // shuffle card
    void shufflePile();

    // show card
    void showPile() const;

    // check empty
    bool isEmpty() const;

    // get card information
    unsigned getPileSize() const;
    unsigned getNo(unsigned) const;
    unsigned getSuit(unsigned) const;

private:
    // card pile
    std::vector<Card> cards;
};

#endif
