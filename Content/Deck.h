#ifndef DECK_H
#define DECK_H


#include<stdlib.h>
#include<vector> 
#include "Card.h"

class Deck{
public:
  Deck();
 
  // List of cards
  std::vector<Card> cards;

  void shuffle();
  //draw one card
  Card& draw();
  
};

#endif 