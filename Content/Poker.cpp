#include<stdlib.h>
#include<vector> 
#include "Poker.h"

Poker::Poker(){

  std::vector<Card> cards;
  std::vector<Player> players;
  int pot = 0;
  int tableBet = 0;
  deck = Deck();
  //create players:

  
  
}

void Poker::play(){
  int pot = 0;
  int tableBet = 0;
  deck = Deck();
  deck.shuffle();
  
  for(Player x : players){
    x.draw(deck.draw());
    x.draw(deck.draw());
  }
  // getinfo();
  // getbet();
  deck.draw();
  
  cards.push_back(deck.draw());
  cards.push_back(deck.draw());
  cards.push_back(deck.draw());

  //getinfo();
  //getbet();

  deck.draw();
  cards.push_back(deck.draw());
  //getinfo();
  //getbet();

  deck.draw();
  cards.push_back(deck.draw());
  //getinfo();
  //getbet();

  
}



