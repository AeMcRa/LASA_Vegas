#include<stdlib.h>
#include<vector> 
#include "Poker.h"
#include <iostream>

Poker::Poker(){

  std::vector<Card> cards;
  std::vector<Player> players;
  int pot = 0;
  int tableBet = 0;
  deck = Deck();

}
void Poker::play() {
    pot = 0;
    tableBet = 0;
    deck = Deck(); // New deck each round
    deck.shuffle();


    for (Player& x : players) {
        x.draw(deck.draw());
        x.draw(deck.draw());
        x.folded = false; // Reset folded status
        x.currentBet = 0; // Reset bet
    }


    for (int round = 0; round < 4; ++round) {
        getbets(round); // Handle betting for each round
        if (round == 0) { table_flip(3); } 
        else { table_flip(1); } 
    }
    determineWinner();

 
    cards.clear(); 
}


void Poker::table_flip(int numCards) {
    for (int i = 0; i < numCards; ++i) {
        cards.push_back(deck.draw());
    }
    // Display the community cards to the players
    std::cout << "Community Cards: ";
    for (Card& c : cards) {
        std::cout << c.getName() << " ";
    }
    std::cout << std::endl;
}

void Poker::getbets(int round) {
    std::vector<Card> cc;
    for(Player p : players){
        for(Card c : p.hand){
            cc.push_back(c);
        }
    }
    for (Player& p : players) {
        if (!p.folded) {
            p.bet(tableBet,cc);
        }
    }
}

void Poker::determineWinner() {
    std::vector<Player*> activePlayers;
    for (Player& p : players) {
        if (!p.folded) {
            activePlayers.push_back(&p); 
        }
    }


    if (activePlayers.size() == 1) {
        std::cout << activePlayers[0]->getName() << " wins the pot of $" << pot << "!" << std::endl;
        activePlayers[0]->gainChips(pot); 
        return; 
    }
    return;
}


bool Poker::checkEndCondition() {
    int playersWithChips = 0;
    for (Player& p : players) {
        if (p.getChips() > 0) {
            playersWithChips++;
        }
    }

    // End the game if only one player has chips left
    if (playersWithChips <= 1) {
        return true; 
    }
    return false; 
}