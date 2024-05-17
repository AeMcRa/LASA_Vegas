
#ifndef CARD_H
#define CARD_H

#include<stdlib.h>
#include<string>

class Card{
public:
  Card();
  Card(int r, int s);

  // 11 = Jack, 12 = Queen, 13 = King, 14 = Ace
  int rank;
  // 1 = Spades, 2 = Hearts, 3 = Clubs, 4 = Diamonds
  int suit;

  // 0 = this card is lesser, 1 = this card is greater, 2 = this card is equal
  int compareRank(Card card);

  bool sameSuit(Card card);

  std::string getName();

 bool operator==(const Card& other) const; 
  
};


#endif