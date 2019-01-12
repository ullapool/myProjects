#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;


class TicTacToe
{
protected:
    vector< vector<char> > pField;


public:
    TicTacToe();
    string showTable();

    void resetField();
    char getWinner();
};

#endif // TICTACTOE_H
