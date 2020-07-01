#pragma once

class MyBoard
{
public:
    int nbTurns = 1;
    int player;
    const int player_one = 1;
    const int player_two = 2;
    const int nbCells = 9;

    char starterCells[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char currentCells[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    /*char bla[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};
    */
    MyBoard();
    ~MyBoard();

    bool isFull();
    bool isWon();
    void drawBoard();
};
