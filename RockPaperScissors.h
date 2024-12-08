#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

#include "Game.h"
#include "Player.h"
#include <string>
#include <iostream>

class RockPaperScissors : public Game {
private:
    Player* player;

public:
    // Default constructor
    RockPaperScissors();

    // Constructor with Player object
    RockPaperScissors(Player* player);

    void play() override;

private:
    std::string getComputerChoice();
    std::string determineWinner(const std::string& playerChoice, const std::string& computerChoice);
};

#endif // ROCKPAPERSCISSORS_H
