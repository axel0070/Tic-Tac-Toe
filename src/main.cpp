// Tic-Tac-Toe game playable through the console
// Small project to get acquainted with C++

#include <iostream>
#include "gameSystem.h"
#include "Board.h"

using namespace std;

int main()
{
    bool isDraw = 0, isWon = 0;
    bool isOver = 0;
    char choice;

    MyBoard GameBoard;
    GameBoard.drawBoard(); //Updates the board and displays it

    while (!isOver)
    {
        choice = startTurn(GameBoard); //Checks if the player's move is allowed
        playerMove(GameBoard, choice);

        GameBoard.drawBoard();

        isWon = GameBoard.isWon(); //checks if a player won the game

        if (isWon != 1)
        {
            isDraw = GameBoard.isFull(); //checks if there are still cells left to play
        }

        isOver = isDraw || isWon;
    }

    return 0;
}
