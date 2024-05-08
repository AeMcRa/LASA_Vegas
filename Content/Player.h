#ifndef PLAYER_H
#define PLAYER_H


#include<stdlib.h>
#include<vector> 
#include<string>
#include "Card.h"

class Player{
public:
  Player();
  Player(std::string n);

  std::vector<Card> hand;
  int chips;
  std::string name;
  bool folded;
  int currentBet;

  std::string getName();
  int getChips();
  int getCurrentBet();
  //draw one card
  void draw(Card c);
  void discard();
  void gainChips(int i);
  void bet();
  void calculatescore( std::vector<Card> cards);
};

class User: public Player{
public:
  User();
  User(std::string n);

  std::vector<Card> hand;
  int chips;
  std::string name;
  bool folded;
  int currentBet;

  void bet(int tableBet);
};

class Bot: public Player{
public:
  Bot();
  Bot(std::string n);

  std::vector<Card> hand;
  int chips;
  std::string name;
  bool folded;
  int currentBet;

  void bet(int tableBet);

};

#endif 