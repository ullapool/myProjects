#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H
#include "tictactoe.h"
#include <string>

class TicTacToeGame : public TicTacToe
{
private:
    string player_1;
    string player_2;
    char currentPlayer;
public:
    TicTacToeGame(string player_1, string player_2);
    bool isfinished();
    void play(int row, int col);
    string winner();
    string getCurrentPlayer();
    string showTable();
};

#endif // TICTACTOEGAME_H
