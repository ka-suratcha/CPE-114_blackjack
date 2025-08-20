# CPE-114_blackjack

## 📖 Overview
This project was created as part of  **CPE-114: Object-Oriented Programming Laboratory**.

The goal of this assignment is to prove that you understand **Object-Oriented Programming (OOP)** concepts such as constructors, class interactions, and encapsulation.

I chose the **Blackjack card game** because it demonstrates the use of **OOP** and **STL containers (vector)** in a practical and engaging way.

### 🎲 About Blackjack
The objective is to have a hand total **closer to 21** than the dealer, without going over (bust).

- Cards with numbers ``2–10`` are worth their face value.
- Face cards ``J, Q, K`` are worth ``10``.
- ``Aces (A)`` can be worth ``1 or 11``, whichever is more favorable.
- Both the player and the dealer are dealt **two cards** at the beginning. 
  - The dealer reveals one card while keeping the other hidden.
- The player can choose to:
  - ``Hit`` → draw another card.
  - ``Stand`` → end their turn.
- If the player’s total exceeds 21, they **bust** and lose automatically.
- After the player stands, the dealer reveals the hidden card and must draw until reaching at least ``17``.
- Outcomes:
  - If the dealer busts, the **player wins**.
  - If neither busts, the totals are compared:
    - Higher total wins.
    - Equal totals result in a **push (tie)**.

---

## ✨ Features
- **Card & Pile Classes**: Using OOP principles to group card properties and change the order of decks.
- **Shuffling and Drawing**: You can move cards around, shuffle them, and draw them.
- **Blackjack Rules**: Follows the usual rules for Blackjack, such as hitting, standing, the dealer drawing to 17, detecting blackjack, and handling busts.
- **User Interaction**: The console asks players what they want to do (`hit` or `stand`).
- **Replay Option**: Lets you play the same game more than once without having to restart the program.
- **Reshuffling**: The deck automatically reshuffles when it runs out of cards.

---

## 🧩 Flowchart
*(To be added later)*  

---

## ▶️ Example Workflow
1. **Game Start**: A new deck is made and shuffled.
2. **First Deal**: The player and the dealer each get two cards. The dealer's second card is hidden.
3. **Player Turn**: The player can either **Hit** (draw a card) or **Stand** (end their turn).
   - The player **busts** if the total is more than 21.
   - If the player gets **Blackjack** (21 with the first two cards), they win right away.
4. **Dealer Turn**: The dealer shows the hidden card.
   - The dealer has to draw cards until they get to at least 17.
   - If the total is more than 21, the dealer **busts**.
5. **Outcome**:
   - The totals are compared.
   - Tell "Win," "Lose," or "Push" (Tie).
6. **Replay**: The player can either play again or leave the game.

---

## 🚀 Future Improvements
- **Betting System**: Put chips, bets, and payout guidelines into practice.
- **GUI Version**: Instead of using a text-based console, create a graphical user interface.
- **Advanced Rules**: Include features like insurance, doubling down, or splitting.
- **Persistent Stats**: Keep player win/loss records throughout sessions.
