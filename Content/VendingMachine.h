// VendingMachine.h
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include "Player.h"
#include <iostream>
#include <vector>
#include <string>


struct Item {
    std::string name;
    int price;
    std::string description; // Description of the item's effect
};

class VendingMachine {
public:
    VendingMachine(); 

    void displayItems() const; 
    bool purchaseItem(Player& player, int itemIndex);

private:
    std::vector<Item> items;
};

#endif 
