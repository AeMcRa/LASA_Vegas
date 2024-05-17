#include "Player.h"
#include <iostream>
#include<string.h>
#include <algorithm>
#include <vector>
#include "Deck.h"

Player::Player(){
  
std::vector<Card> hand;
int chips = 0;
std::string name = "";
bool folded = false;
int currentBet = 0;
}

Player::Player(std::string n){
  std::vector<Card> hand;
  int chips = 3000;
  std::string name = n;
  bool folded = false;
  int currentBet = 0;
}

std::string Player::getName(){
  return this->name;
}

int Player::getChips(){
  return this->chips;
}

int Player::getCurrentBet(){
  return this->currentBet;
}

void Player::draw(Card c){
  this->hand.push_back(c);
}

void Player::discard(){
  this->hand.pop_back();
  this->hand.pop_back();
}

void Player::gainChips(int i){
  chips += i;
}

int Player::bet(int tb, std::vector<Card>& theCards){
  if(tb > chips) return 0;
  return std::max((double)tb,chips * calculateEHS(theCards));
}

double Player::calculateEHS(std::vector<Card>& communityCards) {
    std::vector<Card> h = hand;
    double HS = calculateHandStrength(hand, communityCards); 
    std::pair<double,double> a = calculateHandPotential(hand,communityCards);
    return HS * (1 - a.first) + (1 - HS) * a.second;
}

double Player::calculateHandStrength( std::vector<Card>& hand, std::vector<Card>& communityCards) {
  int ahead = 0, tied = 0, behind = 0;
  int rankInd = 0;

  for (auto& c : communityCards) { 
      int oppRank = c.rank;
      int ourRank =hand.at(rankInd).rank;
      if(rankInd >= hand.size()) break;
      rankInd++;
      if (ourRank > oppRank) ahead += 1;
      else if (ourRank == oppRank) tied += 1;
      else behind += 1;
  }

  return (ahead + tied / 2.0) / (ahead + tied + behind); 
}

std::pair<double, double> Player::calculateHandPotential( std::vector<Card>& hand, 
                                                       std::vector<Card>& communityCards) {
  int HP[3][3] = { {0} }; 
 int HPTotal[3] = {0}; 
  int ourInd = 0;
  int oppInd = 0;


  Deck deck = Deck();


  // Iterate through combinations for the opponents vs player
  for (int i = 0; i < deck.cards.size(); ++i) {
      for (int j = i + 1; j < deck.cards.size(); ++j) {
          std::vector<Card> oppCards = {deck.cards[i], deck.cards[j]};
          int oppRank = communityCards.at(oppInd % communityCards.size()).rank;
          oppInd++;
          int ourRank = hand.at(ourInd % hand.size()).rank;
          ourInd++;
          int index = (ourRank > oppRank) ? 0 : ((ourRank == oppRank) ? 1 : 2);
          HPTotal[index] += 1;

          // Iterate through all possible turn / river
          for (int k = 0; k < deck.cards.size(); ++k) {
              if (k == i || k == j) continue; 
              for (int l = k + 1; l < deck.cards.size(); ++l) {
                  if (l == i || l == j) continue;

                  std::vector<Card> turnRiver = {deck.cards[k], deck.cards[l]};
                  std::vector<Card> board = communityCards;
                  board.insert(board.end(), turnRiver.begin(), turnRiver.end());

                  int ourBest = hand.at(i).rank;
                  int oppBest = hand.at(j).rank;

                  if (ourBest > oppBest) HP[index][0] += 1;
                  else if (ourBest == oppBest) HP[index][1] += 1;
                  else HP[index][2] += 1;
              }
          }
      }
  }

  double PPOT = (HP[2][0] + HP[2][1] / 2.0 + HP[1][0] / 2.0) / (HPTotal[2] + HPTotal[1]);
  double NPOT = (HP[0][2] + HP[1][2] / 2.0 + HP[0][1] / 2.0) / (HPTotal[0] + HPTotal[1]);

  return std::make_pair(PPOT, NPOT); 
}

User::User(){
  
  std::vector<Card> hand;
  int chips = 0;
  std::string name = "";
  bool folded = false;
  int currentBet = 0;
  
}

User::User(std::string n){

  std::vector<Card> hand;
  int chips = 3000;
  std::string name = n;
  bool folded = false;
  int currentBet = 0;
  
}

void User::bet(int tableBet){
  bool valid = false;
  std::cout << "How much would you like to bet? F for fold, C for check. ";
  std::string input;
  while(!valid)
  std::cin >> input;
  if(input == "F"){
    this->folded = true;
    valid = true;
  } else if( input == "C"){
    this->currentBet = tableBet;
    valid = true;
  } else if(!isdigit(input[0]) || stoi(input) < tableBet){
    std::cout << "Invalid input. Please try again with a numerical value higher than the table's current bet." << std::endl;
  } else {
    this->currentBet = stoi(input);
  }
}


Bot::Bot(){

  std::vector<Card> hand;
  int chips = 0;
  std::string name = "";
  bool folded = false;
  int currentBet = 0;

}

Bot::Bot(std::string n){
  std::vector<Card> hand;
  int chips = 3000;
  std::string name = n;
  bool folded = false;
  int currentBet = 0;
}

void Bot::bet(int tableBet){
  this->currentBet = 100;
}