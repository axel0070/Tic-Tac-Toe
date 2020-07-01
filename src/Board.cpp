#include <iostream>
#include "Board.h"

using namespace std;

MyBoard::MyBoard()
{
}

MyBoard::~MyBoard()
{
}

void MyBoard::drawBoard()
{
    if (nbTurns != 1)
    {
        system("cls");
    }
    else
    {
        cout << "Let's play Tic-Tac-Toe !" << endl;
    }

    cout << endl;
    cout << "\t   Turn " << nbTurns << endl; //Header of the game
    cout << endl;

    for (int i = 0; i < 3; i++) //displays the board
    {
        cout << "\t ";

        for (int j = 0; j < 3; j++)
        {
            if (j != 2)
            {
                cout << currentCells[i][j] << " | ";
            }
            else
            {
                cout << currentCells[i][j] << endl;
            }
        }

        if (i < 2)
            cout << "\t-----------" << endl;
    }

    cout << endl;
}
bool MyBoard::isFull()
{
    int checkedCells = 0;
    bool isFull = 0;

    for (int i = 0; i < 3; i++) //counts the number of checked cells
    {
        for (int j = 0; j < 3; j++)
        {
            if (currentCells[i][j] == 'X' || currentCells[i][j] == 'O')
                checkedCells++;
        }
    }

    if (checkedCells == 9) //checks if the board is full, declares Draw if true
    {
        cout << "Draw ! " << endl;
        isFull = 1;
    }

    return isFull; //returns whether the board is full or not
}
bool MyBoard::isWon()
{
    bool isWon = 0;

    bool verticalWin = 0;
    bool horizonWin = 0;
    bool diagWin = 0;

    for (int i = 0; i < 3; i++) //checks the columns, lines and diagonals of the board
    {
        verticalWin = currentCells[0][i] == currentCells[1][i] && currentCells[1][i] == currentCells[2][i];
        horizonWin = currentCells[i][0] == currentCells[i][1] && currentCells[i][1] == currentCells[i][2];

        diagWin = currentCells[i][0] == currentCells[1][1] && currentCells[1][1] == currentCells[2 - i][2];

        if (verticalWin || horizonWin || diagWin) //if any of the 3 is true, the winning condition is fulfilled
            isWon = 1;
    }

    if (isWon)
        cout << "Congratulations Player " << playerID << " ! You win !" << endl;

    return isWon; //returns true if one of the players wins
}