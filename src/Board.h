#pragma once

class MyBoard
{
public:
    int nbTurns = 1;
    int playerID = 1;

    char currentCells[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};

    MyBoard();
    ~MyBoard();

    bool isChecked(char);
    bool isFull();
    bool isWon();
    void drawBoard();
};
