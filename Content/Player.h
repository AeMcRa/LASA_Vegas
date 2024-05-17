#ifndef PLAYER_H
#define PLAYER_H


#include<stdlib.h>
#include<vector> 
#include<string>
#include "Card.h"
#include <algorithm>

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
  void calculatescore( std::vector<Card> cards);
double calculateEHS( std::vector<Card>&);
int bet(int tb,  std::vector<Card>& theCards);
std::pair<double, double> calculateHandPotential( std::vector<Card>& hand, 
 std::vector<Card>& communityCards);
double calculateHandStrength( std::vector<Card>& hand, std::vector<Card>& communityCards);
};


class User: public Player {
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