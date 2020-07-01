// Tic-Tac-Toe game playable through the console
// Small project to get acquainted with C++

#include <iostream>
#include "gameSystem.h"
#include "Board.h"

using namespace std;

int main()
{
    bool isDraw, isWon, isOver, startAgain;
    char choice;

    MyBoard GameBoard;

    do
    {
        isDraw = 0;
        isWon = 0;
        isOver = 0;

        GameBoard.drawBoard(); //Updates the board and displays it

        while (!isOver)
        {
            choice = startTurn(GameBoard); //Checks if the player's move is allowed
            playerMove(GameBoard, choice);

            GameBoard.drawBoard();

            isWon = GameBoard.isWon(); //checks if a player won the game

            if (isWon != 1)
                isDraw = GameBoard.isFull(); //checks if there are still cells left to play

            isOver = isDraw || isWon;
        }

        startAgain = startOver(choice);

        resetGame(GameBoard);

    } while (startAgain);

    cout << endl
         << "Thank you for playing :-) " << endl;
    cout << "Press any key to exit the program ... " << endl;

    return 0;
}
