#pragma once

#include "Board.h"

char startTurn(MyBoard &);
void playerMove(MyBoard &, char);
void resetGame(MyBoard &);
bool startOver(char);