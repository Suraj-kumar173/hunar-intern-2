#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string determineWinner(char player, char computer) {
    if (player == computer)
        return "It's a tie!";
    
    if ((player == 'r' && computer == 's') || 
        (player == 'p' && computer == 'r') || 
        (player == 's' && computer == 'p'))
        return "You win!";
    
    return "Computer wins!";
}

int main() {
    char playerChoice, computerChoice;
    char choices[] = {'r', 'p', 's'};
    
    srand(static_cast<unsigned int>(time(0)));

    cout << "Welcome to Rock-Paper-Scissors!\n";
    cout << "Enter your choice (r for Rock, p for Paper, s for Scissors): ";
    cin >> playerChoice;

    playerChoice = tolower(playerChoice);

    if (playerChoice != 'r' && playerChoice != 'p' && playerChoice != 's') {
        cout << "Invalid choice! Please enter 'r', 'p', or 's'.\n";
        return 1;
    }

    computerChoice = choices[rand() % 3];

    cout << "You chose: " << (playerChoice == 'r' ? "Rock" : playerChoice == 'p' ? "Paper" : "Scissors") << endl;
    cout << "Computer chose: " << (computerChoice == 'r' ? "Rock" : computerChoice == 'p' ? "Paper" : "Scissors") << endl;

    cout << determineWinner(playerChoice, computerChoice) << endl;

    return 0;
}
