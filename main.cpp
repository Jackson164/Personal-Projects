#include <iostream>
#include "TicTacToe.h"
#include "TicTacToe.cpp"


using namespace std;



int main()
{
    ticTacToe Game;
    char playerOneChar = 'X';
    char playerTwoChar = 'O';
    char currentPlayer = '*'; //neither X or O, should not show up in program
    char playAgain = 'n';
    int coordinate = -1;
    int count = 0;


    cout << "------------Tic Tac Toe------------" << endl;
    cout << endl << endl;
    
    do
    {
        if(playAgain == 'y' || playAgain == 'Y')
        {
            Game.resetBoard();
        }
    
        do
        {
            if(count % 2 == 0)
            {
                currentPlayer = 'X';
            }
            else
            {
                currentPlayer = 'O';
            }


            Game.print();

            cout << endl << currentPlayer << "'s move >>";
            cin >> coordinate;
            cout << endl << "-----------------------------------" << endl << endl;


            while(coordinate < 1 || coordinate > 9)
            {
                
                cout << "1 2 3" << endl;
                cout << "4 5 6" << endl;
                cout << "7 8 9" << endl;

                cout << endl << "Invalid input. Enter a value 1-9 to choose square" << endl << endl;
                cin >> coordinate;
            }
            Game.playerTurn(currentPlayer, coordinate);

            count++;
        }
        while (Game.hasWon(currentPlayer) == false);

        Game.print();

        cout << endl << currentPlayer << " won the game!" << endl << endl;
        cout << "Play again? (y/n)\n>>";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');


   return 0;
}