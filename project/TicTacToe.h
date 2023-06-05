#ifndef TICTACTOE_H
#define TICTACTOE_H

class BoardCell {
public:
    char symbol;
};

class TicTacToe {
public:
    static const int SIZE = 3;
    BoardCell board[SIZE][SIZE];

public:
    TicTacToe();

    void displayBoard();

    bool makeMove(int row, int col, char symbol);

    bool isGameOver();
};

#endif
