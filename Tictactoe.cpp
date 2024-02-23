#include "TicTacToe.h"
#include <iostream>


using namespace std;


//default constructor
ticTacToe::ticTacToe()
{

    for(int i = 0; i < BOARD_EDGE_SIZE; i++)
    {
        for(int j = 0; j < BOARD_EDGE_SIZE; j++)
        {
            board[i][j] = 'o';
        }
    }

    currentIndex = -1;
    isWinning = false;
}

//parameterized constructor
ticTacToe::ticTacToe(char Board[BOARD_EDGE_SIZE][BOARD_EDGE_SIZE], int CurrentIndex, bool IsWinning)
{

    for(int i = 0; i < BOARD_EDGE_SIZE; i++)
    {
        for(int j = 0; j < BOARD_EDGE_SIZE; j++)
        {
            board[i][j] = Board[i][j];
        }
    }

    currentIndex = CurrentIndex;
    isWinning = IsWinning;

}

//copy constructor
ticTacToe::ticTacToe(const ticTacToe &tictactoe)
{

    for(int i = 0; i < BOARD_EDGE_SIZE; i++)
    {
        for(int j = 0; j < BOARD_EDGE_SIZE; j++)
        {
            board[i][j] = board[i][j];
        }
    }

    currentIndex = tictactoe.currentIndex;
    isWinning = tictactoe.isWinning;

}

//destructor
ticTacToe::~ticTacToe()
{

}



//getters
int ticTacToe::getCurrentIndex() const
{
    return currentIndex;
}

bool ticTacToe::getIsWinning() const
{
    return isWinning;
}




//setters
void ticTacToe::setCurrentIndex(const int CurrentIndex)
{
    currentIndex = CurrentIndex;
}

void ticTacToe::setArrayValue(int row, int column)
{
    board[row][column] = 'o';
}



//methods
void ticTacToe::playerTurn(const char playerChar, const int choice)
{
    switch(choice)
    {
        case 1:
        board[0][0] = playerChar;
        break;
        case 2:
        board[0][1] = playerChar;
        break;
        case 3:
        board[0][2] = playerChar;
        break;
        case 4:
        board[1][0] = playerChar;
        break;
        case 5:
        board[1][1] = playerChar;
        break;
        case 6:
        board[1][2] = playerChar;
        break;
        case 7:
        board[2][0] = playerChar;
        break;
        case 8:
        board[2][1] = playerChar;
        break;
        case 9:
        board[2][2] = playerChar;
        break;
    }
}

void ticTacToe::resetBoard()
{
    for(int i = 0; i < BOARD_EDGE_SIZE; i++)
    {
        for(int j = 0; j < BOARD_EDGE_SIZE; j++)
        {
            setArrayValue(i, j);
        }
    }
}



bool ticTacToe::hasWon(const char playerChar) const
{
    bool won = false;

    //check horizontals
    if((board[0][0] == playerChar) && (board[0][1] == playerChar) && (board[0][2]) == playerChar)
    {
        won = true;
    }
    else if((board[1][0] == playerChar) && (board[1][1] == playerChar) && (board[1][2]) == playerChar)
    {
        won = true;
    }
    else if((board[2][0] == playerChar) && (board[2][1] == playerChar) && (board[2][2]) == playerChar)
    {
        won = true;
    }

    //check verticals
    else if((board[0][0] == playerChar) && (board[1][0] == playerChar) && (board[2][0]) == playerChar)
    {
        won = true;
    }
    else if((board[0][1] == playerChar) && (board[1][1] == playerChar) && (board[2][1]) == playerChar)
    {
        won = true;
    }
    else if((board[0][2] == playerChar) && (board[1][2] == playerChar) && (board[2][2]) == playerChar)
    {
        won = true;
    }

    //check diagonals
    else if((board[0][0] == playerChar) && (board[1][1] == playerChar) && (board[2][2]) == playerChar)
    {
        won = true;
    }
    else if((board[0][2] == playerChar) && (board[1][1] == playerChar) && (board[2][0]) == playerChar)
    {
        won = true;
    }

    return won;
}

void ticTacToe::print() const
{
    cout << "           -------------" << endl;
    cout << "           | " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << endl;
    cout << "           -------------" << endl;
    cout << "           | " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << endl;
    cout << "           -------------" << endl;
    cout << "           | " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << endl;
    cout << "           -------------" << endl;
}
