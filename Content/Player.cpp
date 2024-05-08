#include "Player.h"
#include <iostream>
#include<string.h>

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

void Player::bet(){
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
  //make bot actually smart
  this->currentBet = 100;
}