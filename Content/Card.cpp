
#include "Card.h"
#include <iostream>
#include <string>

Card::Card(){
  rank = 0;
  suit = 0;
}

Card::Card(int r, int s){
    rank = r;
    suit = s;
   
}

int Card::compareRank(Card card){

  if(rank < card.rank)
    return 0;
  else if(rank > card.rank)
    return 1;
  else
    return 2;
}

bool Card::sameSuit(Card card){
  if(suit == card.suit)
    return true;
  else
    return false;
  
}



std::string Card::getName(){

  std::string name;
  if(rank == 11){
    name +="J";
  } else if( rank == 12){
    name +="Q";
  } else if( rank == 13){
    name +="K";
  } else if( rank == 14){
    name +="A";
  } else{
    name += std::to_string(rank);
  }

  if(suit == 1){
    name +="S";
  }else if(suit == 2){
    name +="H";
  } else if(suit == 3){
    name +="C";
  } else if(suit == 4){
    name +="D";
  }

  return name;
}

