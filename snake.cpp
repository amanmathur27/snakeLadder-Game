#include <bits/stdc++.h>
using namespace std;

// Function to Roll a die and getting a random value of between 1 and 6.
int rollDie()
{
    return rand() % 6 + 1;
}

// Function to move the player in the board
int movePlayer(int currentPosition, int diceRoll)
{
    int newPosition = currentPosition + diceRoll;

    // Creating snakes and ladders in the board.
    int snakes[][2] = {{16, 6}, {47, 26}, {49, 11}, /*...*/};
    int ladders[][2] = {{4, 25}, {11, 40}, {30, 58}, /*...*/};

    // if snake if found
    for (int i = 0; i < sizeof(snakes) / sizeof(snakes[0]); i++)
    {
        if (newPosition == snakes[i][0])
        {
            newPosition = snakes[i][1];
            cout << "Snake bite you! \n";
            break;
        }
    }

    // If ladder is found
    for (int i = 0; i < sizeof(ladders) / sizeof(ladders[0]); i++)
    {
        if (newPosition == ladders[i][0])
        {
            newPosition = ladders[i][1];
            cout << "Yay! you found a ladder\n";
            break;
        }
    }
    return newPosition;
}

int main()
{
    srand(time(0));
    int boardSize = 100;
    int playerPosition = 1;
    cout << "Welcome to the Snake-Ladder Game\n";

    while (playerPosition < boardSize)
    {
        cout << "Current Position of the player is " << playerPosition << endl;
        cout << "Press Enter to roll the dice\n";
        cin.get();
        int diceRoll = rollDie();
        cout << "You rolled the die and got " << diceRoll << endl;
        playerPosition = movePlayer(playerPosition, diceRoll);

        if (playerPosition > boardSize)
        {
            cout << "Hurrey! You won the game " << endl;
        }
    }
    return 0;
}