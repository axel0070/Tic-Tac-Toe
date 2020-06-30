#pragma once

class MyBoard
{
public:
    const int nbCells = 9;
    int nbTurns = 1;
    int player;
    int player_one = 1;
    int player_two = 2;

    char starterCells[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char currentCells[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    MyBoard();
    ~MyBoard();

    bool isFull();
    bool isWon();
    void drawBoard();
};
