#include "Content/Poker.h"
#include "Content/Player.h"
#include "Content/VendingMachine.h" 
#include <iostream>
#include <random>

int main() {
    Poker game; 

    // Initialize Players
    int numPlayers;
    std::cout << "How many players? ";
    std::cin >> numPlayers;

    // Create Vending Machine
    VendingMachine vendingMachine; 
    std::random_device rd;
    std::mt19937 g(rd());

    // Create User object and add to players vector
    std::string userName;
    std::cout << "Enter your name: ";
    std::cin >> userName;
    game.players.push_back(new User(userName));

    // Create Bot objects and add to players vector
    for (int i = 1; i < numPlayers; ++i) {
        game.players.push_back(new Bot("Bot " + std::to_string(i)));
    }


    int gameRounds = 1;

    while (true) { 
        std::cout << "LASA_VEGAS Round #" << gameRounds << "!\n";
        game.play(); // Start a new round
        if (game.checkEndCondition()) {
            break; 
        }
        gameRounds++;
        std::uniform_int_distribution<std::mt19937::result_type> dist10(1,10);
        if(dist10(rd) > 8){
            vendingMachine.displayItems(); 
            int choice;
            std::cout << "Would you like to buy an item (Enter 0 for no)? ";
            std::cin >> choice;
            if (choice != 0) { 
                vendingMachine.purchaseItem(*game.players[0], choice); 
            }
        }

    }

    game.determineWinner();
    
    // Clean up allocated players
    for(auto &x : game.players){
        delete x;
    }

    return 0;
}