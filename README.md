# CPE-114_blackjack

## 📖 Overview
This project was developed as part of **CPE-114: Object-Oriented Programming Laboratory**. 

The goal of this assignment is to prove that you understand **Object-Oriented Programming (OOP)** concepts such as constructors, class interactions, and encapsulation.  

I chose the **Blackjack card game** because it demonstrates the use of **OOP** and **STL containers (vector)** in a practical and engaging way.  

### 🎲 About Blackjack
Blackjack is one of the most popular card games played in casinos. The objective is to have a hand total **closer to 21** than the dealer, without going over (bust).  

- Cards with numbers **2–10** are worth their face value.  
- Face cards **J, Q, K** are worth **10**.  
- **Aces (A)** can be worth **1 or 11**, whichever is more favorable.  
- Both the player and the dealer are dealt **two cards** at the beginning.  
  - The dealer reveals one card while keeping the other hidden.  
- The player can choose to:  
  - **Hit** → draw another card.  
  - **Stand** → finish their turn.  
- If the player’s total exceeds 21, they **bust** and lose automatically.  
- After the player stands, the dealer reveals the hidden card and must draw until reaching at least **17**.  
- Outcomes:  
  - If the dealer busts, the **player wins**.  
  - If neither busts, the totals are compared:  
    - Higher total wins.  
    - Equal totals result in a **push (tie)**.  
- A starting hand of an **Ace + 10-value card** is a **Blackjack**, the strongest hand.  


---

## ✨ Features
- **Card & Pile Classes**: Encapsulation of card properties and deck manipulation using OOP principles.  
- **Shuffling & Drawing**: Cards can be shuffled, drawn, and moved between piles.  
- **Blackjack Rules**: Implements standard Blackjack rules (hit, stand, dealer draws to 17, blackjack detection, bust handling).  
- **User Interaction**: Console-based prompts for player actions (`hit` or `stand`).  
- **Replay Option**: Allows multiple game rounds without restarting the program.  
- **Reshuffling**: Automatically reshuffles when the deck runs out of cards.  

---

## 🧩 Flowchart
*(To be added later)*  

---

## ▶️ Example Workflow
1. **Game Start**: A new shuffled deck is created.  
2. **Initial Deal**: Both player and dealer receive 2 cards. Dealer’s second card is hidden.  
3. **Player Turn**:  
   - Player can choose to **Hit** (draw a card) or **Stand** (end turn).  
   - If the total exceeds 21, the player **busts**.  
   - If the player has **Blackjack** (21 with first two cards), the player wins.  
4. **Dealer Turn**:  
   - Dealer reveals hidden card.  
   - Dealer must draw until the total is at least 17.  
   - If the dealer exceeds 21, the dealer **busts**.  
5. **Result**:  
   - Totals are compared.  
   - Declare **Win / Lose / Push (Tie)**.  
6. **Replay**: Prompt the player to play again or exit.  

---

## 🚀 Future Improvements
- **Betting System**: Implement chips, wagers, and payout rules.  
- **GUI Version**: Create a graphical interface instead of text-based console.  
- **Advanced Rules**: Add features like splitting, doubling down, or insurance.  
- **Persistent Stats**: Save player win/loss records across sessions.  

