#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Card.h"

class Player {
protected:
    std::vector<Card> hand;
    int chips;
    std::string name;
    bool folded;
    int currentBet;

public:
    Player();
    Player(std::string n);
    virtual ~Player();

    std::string getName();
    int getChips();
    int getCurrentBet();
    void draw(Card c);
    void discard();
    void gainChips(int i);

    std::vector<Card> getHand();
    bool hasFolded();
    void resetFold();
    void resetCurrentBet();

    virtual void bet(int tb, std::vector<Card>& theCards) = 0; // Make bet a virtual function
    double calculateEHS(std::vector<Card>& );
    double calculateHandStrength( std::vector<Card>& h, std::vector<Card>& cc);
    std::pair<double, double> calculateHandPotential(std::vector<Card>& h, 
                                                       std::vector<Card>& cc);
};

class User : public Player {
public:
    User();
    User(std::string n);

    void bet(int tableBet, std::vector<Card>& theCards) override;
};

class Bot : public Player {
public:
    Bot();
    Bot(std::string n);

    void bet(int tableBet,std::vector<Card>& theCards) override;
};

#endif // PLAYER_H
