#include "tictactoegame.h"
#include "exception.h"
#include <sstream>
#include <string>

TicTacToeGame::TicTacToeGame(string player_1, string player_2)
{
   this->player_1 = player_1;
   this->player_2 = player_2;
   currentPlayer = 'x';
}

string TicTacToeGame::showTable(){
    stringstream result;

    result <<TicTacToe::showTable()<<endl;

    return result.str();
}

bool TicTacToeGame :: isfinished(){
    char winner = getWinner();
    if(winner == ' '){
        return false;
    }
    if(winner == 'x'){
        this->winner();
        return true;
    }
    if(winner == 'o'){
        this->winner();
        return true;
    }

  return false;
}

string TicTacToeGame :: winner(){
    if(currentPlayer != 'x'){
        return player_1;
    }
    else{
        return player_2;
    }
}

void TicTacToeGame::play(int row, int col){

    //Validierungs condition
    if(row < 0 || row >= pField.size()){
        throw exception() ;
    }
    if(col < 0 || col >= pField[row].size()){
        throw exception();
    }
    if(pField[row][col] != ' '){
        //cout<<"Oups, field already taken! -> choose anotherone:"<<endl;
        throw exception();
    }

    this->pField[row][col] = currentPlayer;
    if(currentPlayer == 'x'){
        currentPlayer = 'o';
    }
    else{
        currentPlayer = 'x';
    }

}

string TicTacToeGame :: getCurrentPlayer(){
    if(currentPlayer == 'x'){
        return player_1;
    }
    else {
        return player_2;
    }
}


