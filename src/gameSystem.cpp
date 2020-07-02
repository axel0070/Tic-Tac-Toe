#include <iostream>
#include "gameSystem.h"

using namespace std;

char startTurn(MyBoard &Board)
{
    char input, cell;
    bool done = 0, isCellChecked = 0;

    Board.playerID = (Board.nbTurns % 2 != 0) ? 1 : 2; //picks which player (1 or 2) should play this turn

    cout << "Player " << Board.playerID << "'s turn ! ";
    cout << "Make your move : ";

    cin >> input;
    cin.ignore(1024, '\n');

    do
    {
        isCellChecked = Board.isChecked(input);

        if ((input >= '1' && input <= '9') && !isCellChecked) //checks if the input is between '1' and '9' and if the cell is free
        {
            done = 1;
        }
        else
        {
            if (isCellChecked)
            {
                cout << endl
                     << "Invalid choice, must be an available cell" << endl;
                cout << "Pick again : ";
            }
            else
            {
                cout << endl
                     << "Invalid choice, must be a number between 1 and 9" << endl;
                cout << "Pick again : ";
            }

            cin >> input;
            cin.ignore(1024, '\n');
        }

    } while (!done); // Control loop of the player's choice

    return input; //returns a correct move
}

void playerMove(MyBoard &Board, char choice)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (choice == Board.currentCells[i][j])                              //if the choice is available
                Board.currentCells[i][j] = (Board.nbTurns % 2 != 0) ? 'X' : 'O'; //checks the chosen cell
        }
    }

    Board.nbTurns++;
}

void resetGame(MyBoard &Board)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            Board.currentCells[i][j] = '0' + (i * 3) + (j + 1); //reset the 2D array into the original disposition
    }

    Board.playerID = 1; //reset player's turn
    Board.nbTurns = 1;

    system("cls");
}

bool startOver(char choice)
{

    bool result = 0, correct = 0;

    do
    {
        cout << "Would you like to play again ? Must enter y-Y/n-N" << endl;
        cin >> choice;
        cin.ignore(1024, '\n');

        if (choice == 'y' || choice == 'Y')
        {
            correct = 1;
            result = 1;
        }
        else if (choice == 'n' || choice == 'N')
        {
            correct = 1;
            result = 0;
        }
    } while (!correct); //Control loop for the player's choice

    return result; //returns true if the player wants to start again
}
