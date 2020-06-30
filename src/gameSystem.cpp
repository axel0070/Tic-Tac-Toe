#include <iostream>
#include "gameSystem.h"

using namespace std;

char startTurn(MyBoard &Board)
{
    char input;
    bool done = 0;

    if (Board.nbTurns % 2 != 0)
    {
        Board.player = Board.player_one;
    }
    else
    {
        Board.player = Board.player_two;
    }

    cout << "Player " << Board.player << "'s turn ! " << endl;
    cout << "Make your move : ";

    cin >> input;
    cin.ignore(1024, '\n');

    do
    {
        for (int i = 0; i < Board.nbCells; i++)
        {
            if (input == Board.currentCells[i] && input == Board.starterCells[i])
            {
                done = 1;
            }
        }
        if (!done)
        {
            cout << endl
                 << "Invalid choice, must be a correct and available number" << endl;
            cout << "Pick again : ";

            cin >> input;
            cin.ignore(1024, '\n');
        }
    } while (!done);

    return input;
}
void playerMove(MyBoard &Board, char choice)
{
    for (int i = 0; i < Board.nbCells; i++)
    {
        if (choice == Board.currentCells[i])
        {
            if (Board.nbTurns % 2 != 0)
            {
                Board.currentCells[i] = 'X';
            }
            else
            {
                Board.currentCells[i] = 'O';
            }
        }
    }

    Board.nbTurns++;
}