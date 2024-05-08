#include<stdlib.h>
#include<vector> 
#include "Deck.h"
#include "Player.h"

class Poker{
public:
  Poker();

  Deck deck;
  std::vector<Card> cards;
  std::vector<Player> players;
  int pot;
  int tableBet;

  void play();
  void gameinfo();
  void getbets();
  void table_flip();
};

