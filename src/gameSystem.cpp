#include <iostream>
#include "gameSystem.h"

using namespace std;

char startTurn(MyBoard &Board)
{
    char input;
    bool done = 0;

    Board.player = (Board.nbTurns % 2 != 0) ? Board.player_one : Board.player_two;

    cout << "Player " << Board.player << "'s turn ! ";
    cout << "Make your move : ";

    cin >> input;
    cin.ignore(1024, '\n');

    do
    {
        for (int i = 0; i < Board.nbCells; i++)
        {
            if (input == Board.currentCells[i] && input == Board.starterCells[i])
                done = 1;
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
            Board.currentCells[i] = (Board.nbTurns % 2 != 0) ? 'X' : 'O';
    }

    Board.nbTurns++;
}

void resetGame(MyBoard &Board)
{
    for (int i = 0; i < Board.nbCells; i++)
    {
        Board.currentCells[i] = Board.starterCells[i];
    }

    Board.player = 1;
    Board.nbTurns = 1;

    system("cls");
}

bool startOver(char choice)
{
    bool result = 0;
    bool correct = 0;

    cout << "Would you like to play again ? Y/N" << endl;
    cin >> choice;
    //cin.ignore(1024, '\n');

    /*Erreur de logique, ici il y a deux entrées d'affile.
    Il faudrait checker la première entrée PUIS voir si il faut rentrer dans le while*/

    while (!correct)
    {
        cout << "Entry must be y/Y or n/N" << endl;
        cin >> choice;

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
    }

    return result;
}