#include <iostream>
#include "Board.h"

using namespace std;

MyBoard::MyBoard()
{
    cout << "Let's play !" << endl;
}

MyBoard::~MyBoard()
{
    cout << "End of the game" << endl;
}

void MyBoard::drawBoard()
{
    system("cls");

    cout << "Tic-Tac-Toe - Turn " << nbTurns << endl;
    cout << endl;
    cout << " " << currentCells[0] << " | " << currentCells[1] << " | " << currentCells[2] << endl;
    cout << "-----------" << endl;
    cout << " " << currentCells[3] << " | " << currentCells[4] << " | " << currentCells[5] << endl;
    cout << "-----------" << std::endl;
    cout << " " << currentCells[6] << " | " << currentCells[7] << " | " << currentCells[8] << endl;
    cout << endl;
}
bool MyBoard::isFull()
{
    int checkedCells = 0;
    bool isFull = 0;

    for (int i = 0; i < nbCells; i++)
    {
        if ('X' == currentCells[i] || 'O' == currentCells[i])
        {
            checkedCells++;
        }
    }
    if (checkedCells == nbCells)
    {
        cout << "Draw ! " << endl;
        isFull = 1;
    }
    return isFull;
}
bool MyBoard::isWon()
{
    bool isWon = 0;

    bool verticalWin = 0;
    int vertStep;

    bool horizonWin = 0;
    int horizonStep;

    bool diagCondition1;
    bool diagCondition2;

    for (int i = 0; i < 3; i++)
    {
        vertStep = i;
        verticalWin = currentCells[0 + vertStep] == currentCells[3 + vertStep] && currentCells[3 + vertStep] == currentCells[6 + vertStep];

        horizonStep = i * 3;
        horizonWin = currentCells[0 + horizonStep] == currentCells[1 + horizonStep] && currentCells[1 + horizonStep] == currentCells[2 + horizonStep];

        if (verticalWin || horizonWin)
        {
            isWon = 1;
        }
    }

    diagCondition1 = currentCells[0] == currentCells[4] && currentCells[4] == currentCells[8];
    diagCondition2 = currentCells[2] == currentCells[4] && currentCells[4] == currentCells[6];

    if (isWon == 0 && (diagCondition1 || diagCondition2))
    {
        isWon = 1;
    }
    if (isWon)
    {
        cout << "Congratulations Player " << player << " ! You win !" << endl;
    }

    return isWon;
}