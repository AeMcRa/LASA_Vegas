#include "VendingMachine.h"

VendingMachine::VendingMachine() {

    items = {
        {"Peek", 500, "See one of your opponent's cards!"},
        {"Swap", 1000, "Swap one of your cards with a random card!"},
        {"Double Down", 1500, "Double your next bet's winnings!"}
    };
}

void VendingMachine::displayItems() const {
    std::cout << "\nWelcome to the Vending Machine! Here's what we have:\n" << std::endl;
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << i + 1 << ". " << items[i].name 
                  << " - $" << items[i].price 
                  << " - " << items[i].description << std::endl;
    }
}

bool VendingMachine::purchaseItem(Player& player, int itemIndex) {
    if (itemIndex < 1 || itemIndex > items.size()) {
        std::cout << "Invalid item number!" << std::endl;
        return false;
    }

    int actualIndex = itemIndex - 1;
    if (player.getChips() >= items[actualIndex].price) {
        player.gainChips(-items[actualIndex].price);
        std::cout << player.getName() << " bought a " 
                  << items[actualIndex].name << "!" << std::endl;

        return true;
    } else {
        std::cout << "Not enough chips!" << std::endl;
        return false;
    }
}