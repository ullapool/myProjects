#include <iostream>
#include "tictactoe.h"
#include "tictactoegame.h"
#include <vector>
#include "exception.h"
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string player1;
    string player2;

    cout<<"Welcome to a new Game of Tic Tac Toe:"<<endl;
    cout<<"#####################################"<<endl;
    cout<<"\n\n";
    cout<<"Enter name for Player 1 [x]: "; cin>>player1;
    cout<<"Enter name for Player 2 [o]: "; cin>>player2;
    TicTacToeGame game(player1, player2);
    char choice;
    do{
    while(!game.isfinished())
    {

        int row, col;
        cout<<game.showTable();
        cout<<"Please enter a Position "<<game.getCurrentPlayer()<<" :"<<endl;
        cout<<"Row: ";
        cin>>row;
        cout<<"Col.: ";
        cin>>col;
        try {
             game.play(row, col);
        } catch (exception &e) {
            cout<<"Field already taken. Choose another one:"<<endl;
        }

      }

    cout<<game.showTable();
    string result = game.winner();
    if(result != " "){
       cout<<"**Congratulations "<<result<<" YOU won!!**"<<"\n\n";
    }else cout<<"--Draw--"<<"\n\n";
    cout<<player1<<": "<<game.counter1<<"  |  "<<player2<<": "<<game.counter2<<endl;
    cout<<"Do you want to play again? - (Y)"<<endl;
    cout<<"No thanks. - (N)"<<endl;

    cin>>choice;
    switch (choice) {

      case ('Y'):
      case ('y'):
    {
         game.resetField();
    }





    break;
    case ('N'):
    case ('n'):
    {
        cout<<"**Goodbye**"<<endl;
    }

    break;

    }
  }
    while(choice != 'n' );

    return 0;

}




