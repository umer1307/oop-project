#include "RockPaperScissors.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

RockPaperScissors::RockPaperScissors() : Game("Rock, Paper, Scissors") {
    player = new Player();  // Create a default player if not passed
}

RockPaperScissors::RockPaperScissors(Player* player) : Game("Rock, Paper, Scissors"), player(player) {}

void RockPaperScissors::play() {
    std::string playerChoiceStr;
    std::cout << "Enter your choice:\n";
    std::cout << "0: Rock\n1: Paper\n2: Scissors\n";
    std::cout << "Or type 'Rock', 'Paper', or 'Scissors': ";
    std::cin >> playerChoiceStr;

    // Convert input to lowercase to handle case insensitivity
    std::transform(playerChoiceStr.begin(), playerChoiceStr.end(), playerChoiceStr.begin(), ::tolower);

    // If the input is numeric (0, 1, 2), convert it to the corresponding string
    if (playerChoiceStr == "0" || playerChoiceStr == "rock") {
        playerChoiceStr = "Rock";
    }
    else if (playerChoiceStr == "1" || playerChoiceStr == "paper") {
        playerChoiceStr = "Paper";
    }
    else if (playerChoiceStr == "2" || playerChoiceStr == "scissors") {
        playerChoiceStr = "Scissors";
    }
    else {
        std::cout << "Invalid choice. Please enter 0, 1, 2 or 'Rock', 'Paper', 'Scissors'.\n";
        return;
    }

    std::string computerChoice = getComputerChoice();
    std::cout << "Computer chose: " << computerChoice << "\n";

    std::string result = determineWinner(playerChoiceStr, computerChoice);
    std::cout << result << "\n";

    if (result == "You win!") {
        player->addBadge("Rock, Paper, Scissors Champion");
    }
}

std::string RockPaperScissors::getComputerChoice() {
    // Randomly generate computer's choice
    std::srand(static_cast<unsigned int>(std::time(0)));  // Seed the random generator
    int choice = std::rand() % 3;
    switch (choice) {
    case 0: return "Rock";
    case 1: return "Paper";
    case 2: return "Scissors";
    default: return "Rock";  // Default case
    }
}

std::string RockPaperScissors::determineWinner(const std::string& playerChoice, const std::string& computerChoice) {
    if (playerChoice == computerChoice) {
        return "It's a tie!";
    }
    else if ((playerChoice == "Rock" && computerChoice == "Scissors") ||
        (playerChoice == "Paper" && computerChoice == "Rock") ||
        (playerChoice == "Scissors" && computerChoice == "Paper")) {
        return "You win!";
    }
    else {
        return "You lose!";
    }
}
