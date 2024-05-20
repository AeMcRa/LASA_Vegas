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
    tableBet = 100;
    deck = Deck(); // New deck each round
    deck.shuffle();

    for (Player& x : players) {
        Card c1 = deck.draw();
        if(c1.rank == -1 && c1.suit == -1){
            break;
        }
        x.draw(c1);
        Card c2 = deck.draw();
        if(c2.rank == -1 && c2.suit == -1){
            break;
        }
        x.draw(c2);
        x.folded = false; // Reset folded status
        x.currentBet = 0; // Reset bet
    }

    for (int round = 0; round < 4; ++round) {
        getbets(round); // Handle betting for each round
        if (round == 0) { table_flip(3); } 
        else { table_flip(1); } 
    }
    determineWinner();
}


void Poker::table_flip(int numCards) {
    std::vector<Card> commCards;
    for (int i = 0; i < numCards; ++i) {
        commCards.push_back(deck.draw());
    }
    // Display the community cards to the players
    std::cout << "Community Cards: ";
    for (Card& c : commCards) {
        std::cout << c.getName() << " ";
    }
    std::cout << "\n";
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
        std::cout << activePlayers[0]->getName() << " wins the pot of $" << pot << "!\n";
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