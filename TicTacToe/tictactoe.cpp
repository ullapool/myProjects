#include "tictactoe.h"
#include "exception.h"
#include <sstream>

TicTacToe::TicTacToe()
{
    pField = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };

}
void TicTacToe::resetField(){
    unsigned char reset = ' ' ;
    for(unsigned int i = 0; i < pField.at(0).size(); i++){
        for(unsigned int j = 0; j < pField.at(0).size(); j++){
            pField.at(i).at(j) = reset;
        }
    }
    cout<<"after reset"<<endl;
    for(const auto row : pField){
        cout<<" | ";
        for(const auto item : row){
            cout<<item<<" | ";
        }
        cout<<endl;
    }

}

string TicTacToe:: showTable(){
    stringstream result;

    for(auto const & row : pField){
        result <<" | ";
        for(auto const& item : row) {
            result <<item<< " | ";
        }
        result <<endl;

    }

    return result.str();
}

char TicTacToe:: getWinner(){

    // removed static_cast<char>
    for(int i = 0; i <= 2; i++){
        if(pField.at(i).at(0) != ' ' && pField.at(i).at(0) == pField.at(i).at(1)
           && pField.at(i).at(0) == pField.at(i).at(2))
        {
           return  (pField.at(i).at(0) );
        }
    }
    for(int i = 0; i <= 2; i++){
        if(pField.at(0).at(i) != ' ' && pField.at(0).at(i) == pField.at(1).at(i)
           && pField.at(0).at(i) == pField.at(2).at(i) )
        {
            return (pField.at(i).at(0) );
        }
    }
    if(pField.at(1).at(1) != ' '){
        if(pField.at(0).at(0) == pField.at(1).at(1) && pField.at(0).at(0) == pField.at(2).at(2)){
           return (pField.at(0).at(0) );
        }
        if(pField.at(0).at(2) == pField.at(1).at(1) && pField.at(0).at(2) == pField.at(2).at(0)){
           return (pField.at(0).at(2) );
        }

    }
    return 0;
}

