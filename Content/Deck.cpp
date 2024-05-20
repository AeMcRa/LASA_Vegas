#include "Deck.h"
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

Deck::Deck(){
  for(int i = 1; i <= 4; i++)
    for(int j = 2; j <= 14; j++) { 
      Card newcard = Card(j,i);
      cards.push_back(newcard);
    }
}

void Deck::shuffle() {
  std::random_device rd;
  std::mt19937 g(rd());

  for(int i = 0; i < 5; i++) {
    std::shuffle(cards.begin(), cards.end(), g);
  }

}

Card& Deck::draw(){
  // Invalid card, empty deck condition.
  if(cards.empty()) {
    Card c = Card(-1,-1);
    return c;
  }
  shuffle();
  Card &drawn = cards.back();
  cards.pop_back();
  return drawn;
}


