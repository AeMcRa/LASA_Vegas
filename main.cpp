#include "Content/Poker.h"
#include "Content/Player.h"
#include "Content/VendingMachine.h" 
#include <iostream>
#include <random>

int main() {
    Poker game; 

    //Initialize Players
    int numPlayers;
    std::cout << "How many players? ";
    std::cin >> numPlayers;


    VendingMachine vendingMachine; 
    std::random_device rd;
    std::mt19937 g(rd());

    
    game.players.push_back(User("You"));
    for (int i = 1; i < numPlayers; ++i) {
        game.players.push_back(Bot("Bot " + std::to_string(i))); 
    }


    while (true) { 
        game.play(); // Start a new round
        if (game.checkEndCondition()) {
            break; 
        }
        std::uniform_int_distribution<std::mt19937::result_type> dist10(1,10);
        if(dist10(rd) > 7){
            vendingMachine.displayItems(); 
            int choice;
            std::cout << "Would you like to buy an item (Enter 0 for no)? ";
            std::cin >> choice;
            if (choice != 0) { 
                vendingMachine.purchaseItem(game.players[0], choice); 
            }
        }

    }


    game.determineWinner();
    return 0;
}