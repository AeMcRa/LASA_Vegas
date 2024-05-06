#ifndef PLAYER_H
#define PLAYER_H


#include<stdlib.h>
#include<vector> 
#include "Card.h"

class Player{
public:
  Player();

  std::vector<Card> hand;
  int chips;

  int getChips();
  //draw one card
  void draw(Card c);

};

#endif 