#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to roll a die and return a random number between 1 and 6
int rollDie() {
    return rand() % 6 + 1;
}

int main() {
    srand(time(NULL));  // Seed the random number generator with the current time

    const int boardSize = 30;  // Size of the board
    int playerPosition = 0;    // Initial player position

    while (playerPosition < boardSize) {
        cout << "Press Enter to roll the die...";
        cin.get();

        int roll = rollDie();
        cout << "You rolled a " << roll << endl;

        playerPosition += roll;

        if (playerPosition > boardSize) {
            playerPosition = boardSize - (playerPosition - boardSize);
        }

        cout << "You are now at position " << playerPosition << endl;

        // Check for Snake and Ladder positions
        switch (playerPosition) {
            case 3: playerPosition = 22; break;  // Ladder
            case 11: playerPosition = 26; break; // Ladder
            case 17: playerPosition = 4; break;  // Snake
            case 19: playerPosition = 7; break;  // Snake
            case 21: playerPosition = 9; break;  // Snake
            case 27: playerPosition = 1; break;  // Snake
        }

        if (playerPosition == boardSize) {
            cout << "Congratulations! You reached the end of the board!" << endl;
            break;
        }
    }

    return 0;
}

/* 
 # In this code:

 1 -> The game board size is set to 30.
 2 -> The player starts at position 0 and rolls a die with values from 1 to 6.
 3 -> The player's position is updated based on the roll.
 4 -> There are predefined Snake and Ladder positions, which are checked and applied as the player moves.
 5 -> The game continues until the player reaches or exceeds the board's size.

 */