#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <cctype>

#include "card.h"
#include "pile.h"

using namespace std;

// helper
void clearScreen() { cout << "\x1B[2J\x1B[H"; }
void sleep_ms(int ms) { this_thread::sleep_for(chrono::milliseconds(ms)); }

// deck safety
static void ensureDeckNotEmpty(Pile& deck) {
    if (deck.isEmpty()) {
        deck = Pile(52);
        deck.shufflePile();
        std::cout << "[Reshuffling a new deck]\n";
    }
}
static void drawSafe(Pile& deck, Pile& to) {
    ensureDeckNotEmpty(deck);
    deck.drawAndInsertTo(to);
}

// total
int getTotal(const Pile &p) {
    int sum = 0, aces = 0;
    for (unsigned i = 0; i < p.getPileSize(); ++i) {
        unsigned no = p.getNo(i);
        if (no == 1)
        { // Ace
            ++aces;
            sum += 1;
        }
        else
            sum += (no > 10) ? 10 : no;
    }
    while (aces > 0 && sum + 10 <= 21) {
        sum += 10;
        --aces;
    }
    return sum;
}

// UI
static void showHands(const Pile& Dealer, const Pile& player, bool hideDealerHole) {
    cout << "Dealer :\n";
    if (hideDealerHole && Dealer.getPileSize() > 0) {
        // show only first card, hide the rest
        Card up = Card(Dealer.getNo(0), Dealer.getSuit(0));
        up.showCard();
        if (Dealer.getPileSize() > 1) {
            cout << "?? (hidden)\n";
        }
        cout << "= Dealer visible total: "
              << ((Dealer.getNo(0) > 10) ? 10 : (Dealer.getNo(0) == 1 ? 11 : Dealer.getNo(0)))
              << " (approx)\n\n";
    } else {
        Dealer.showPile();
        cout << "= Dealer total : " << getTotal(Dealer) << "\n\n";
    }

    cout << "Player :\n";
    player.showPile();
    cout << "= player total : " << getTotal(player) << "\n";
}
static bool promptYesNo(const std::string& msg) {
    char c;
    std::cout << msg << " (y/n): ";
    std::cin >> c;
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return c == 'y';
}

// round setup
static void dealInitial(Pile& deck, Pile& Dealer, Pile& player) {
    Dealer = Pile(0);
    player = Pile(0);

    // fresh deck each round for simplicity & fairness
    deck = Pile(52);
    deck.shufflePile();

    drawSafe(deck, Dealer);
    drawSafe(deck, Dealer);
    drawSafe(deck, player);
    drawSafe(deck, player);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Pile deck, dealer, player;
    
    START_ROUND:
        // brand-new deck + fresh deal every round
        dealInitial(deck, dealer, player);
        cout << "++++++++++++++++++++++++++++++++++\n";

        // ===== Player phase =====
        while (true) {
            clearScreen();

            showHands(dealer, player, true);

            int pTotal = getTotal(player);
            int dTotal = getTotal(dealer);

            // immediate outcomes during player phase
            if (dTotal == 21 && dealer.getPileSize() == 2) {
                cout << "==========================" << endl;
                clearScreen();
                showHands(dealer, player, false);
                cout << "!! Dealer has blackjack. Dealer wins !!\n";
                if (promptYesNo("Play again?")) goto START_ROUND;
                return 0;
            }
            if (pTotal == 21 && player.getPileSize() == 2) {
                cout << "==========================" << endl;
                clearScreen();
                showHands(dealer, player, false);
                cout << "!! Player has blackjack. You win !!\n";
                if (promptYesNo("Play again?")) goto START_ROUND;
                return 0;
            }
            if (pTotal > 21) {
                cout << "==========================" << endl;
                clearScreen();
                showHands(dealer, player, false);
                cout << "!! Player busts. Dealer wins !!\n";
                if (promptYesNo("Play again?")) goto START_ROUND;
                return 0;
            }

            cout << "\n--- hit or stand (h/s): ";
            char cmd; cin >> cmd;
            cmd = static_cast<char>(tolower(static_cast<unsigned char>(cmd)));

            cout << "==========================" << endl;
            if (cmd == 'h') {
                if (deck.isEmpty()) {               // optional: if you ever run out mid-round
                    cout << "[Deck exhausted. Redealing...]\n";
                    goto START_ROUND;
                }
                deck.drawAndInsertTo(player);
            } else if (cmd == 's') {
                break; // go to dealer phase
            } else {
                cout << "(type h for HIT and s for STAND)\n";
                sleep_ms(10000);
            }
        }
        
        // ===== Dealer phase =====
        clearScreen();
        cout << "Dealer is thinking...\n";
        sleep_ms(1200);

        // Dealer draws to 17 or more (standard rule; treat soft 17 as stand by default)
        while (getTotal(dealer) < 17) {
            drawSafe(deck, dealer);
            clearScreen();
            cout << "Dealer draws a card...\n";
            sleep_ms(700);
        }

        // ===== Resolve =====
        cout << "==========================" << endl;
        clearScreen();
        showHands(dealer, player, /*hideDealerHole=*/false);

        int p = getTotal(player);
        int d = getTotal(dealer);

        if (d > 21)         cout << "\n!! Dealer busts. Player wins !!\n";
        else if (p > d)     cout << "\n!! Player wins !!\n";
        else if (p < d)     cout << "\n!! Dealer wins !!\n";
        else                cout << "\n-- Push (tie). --\n";


        if (promptYesNo("Play again?"))goto START_ROUND;
        return 0;
}
