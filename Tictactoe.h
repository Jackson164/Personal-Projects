#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>

using namespace std;

const int BOARD_EDGE_SIZE = 3;

class ticTacToe
{
    public:
        ticTacToe();
        ticTacToe(char playingBoard[BOARD_EDGE_SIZE][BOARD_EDGE_SIZE], int currentIndex, bool isWinning);
        ticTacToe(const ticTacToe &tictactoe);

        //destructor
        ~ticTacToe();

        //getters
        int getCurrentIndex() const;
        bool getIsWinning() const;

        //setters
        void setCurrentIndex(const int currentIndex);
        void setArrayValue(int row, int column);
        //methods
        void playerTurn(const char playerChar, const int choice);
        void resetBoard();
        bool hasWon(const char playerChar) const;
        void print() const;

    private:
        char board[BOARD_EDGE_SIZE][BOARD_EDGE_SIZE];
        int currentIndex;
        bool isWinning;
};

#endif