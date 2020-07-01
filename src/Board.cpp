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

    cout << endl
         << "\t   Turn " << nbTurns << endl;
    cout << endl;
    cout << "\t " << currentCells[0] << " | " << currentCells[1] << " | " << currentCells[2] << endl;
    cout << "\t-----------" << endl;
    cout << "\t " << currentCells[3] << " | " << currentCells[4] << " | " << currentCells[5] << endl;
    cout << "\t-----------" << endl;
    cout << "\t " << currentCells[6] << " | " << currentCells[7] << " | " << currentCells[8] << endl;
    cout << endl;

    /*for(int i = 0 ; i < 9 ; i+=3)
    cout << "\t " << currentCells[i] << " | " << currentCells[i+1] << " | " << currentCells[i+2] << endl;*/
}
bool MyBoard::isFull()
{
    int checkedCells = 0;
    bool isFull = 0;

    for (int i = 0; i < nbCells; i++)
    {
        if ('X' == currentCells[i] || 'O' == currentCells[i])
            checkedCells++;
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
            isWon = 1;
    }

    diagCondition1 = currentCells[0] == currentCells[4] && currentCells[4] == currentCells[8];
    diagCondition2 = currentCells[2] == currentCells[4] && currentCells[4] == currentCells[6];

    if (isWon == 0 && (diagCondition1 || diagCondition2))
        isWon = 1;

    if (isWon)
        cout << "Congratulations Player " << player << " ! You win !" << endl;

    return isWon;
}