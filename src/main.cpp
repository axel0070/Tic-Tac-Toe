// Tic-Tac-Toe game playable through the console
// Small project to get acquainted with C++

#include <iostream>
#include <conio.h>
#include "Board.h"
#include "gameSystem.h"

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

        while (!isOver) //Main game loop
        {
            choice = startTurn(GameBoard); //Checks if the player's move is allowed
            playerMove(GameBoard, choice); //Then plays it

            GameBoard.drawBoard();

            isWon = GameBoard.isWon(); //checks if a player won the game

            if (isWon != 1)
                isDraw = GameBoard.isFull(); //checks if there are still cells left to play

            isOver = isDraw || isWon;
        }

        startAgain = startOver(choice);

        if (startAgain)
            resetGame(GameBoard);

    } while (startAgain); //Loops until the player wants to stop playing

    cout << endl
         << "Thank you for playing :-) " << endl;
    cout << "Press any key to exit the program ... " << endl;
    getch();

    return 0;
}
