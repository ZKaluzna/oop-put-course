#include "TicTacToe.h"
#include <stdexcept>

using namespace std;

TicTacToe::TicTacToe() {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            board[row][col].symbol = ' ';
        }
    }
}

void TicTacToe::displayBoard() {
    cout << "   1   2   3  " << endl;
    cout << "  --- --- ---" << endl;
    for (int row = 0; row < SIZE; ++row) {
        cout << row + 1 << " ";
        for (int col = 0; col < SIZE; ++col) {
            cout << "| " << board[row][col].symbol << " ";
        }
        cout << "|" << endl;
        cout << "  --- --- ---" << endl;
    }
}

bool TicTacToe::makeMove(int row, int col, char symbol) {
    --row;
    --col;

    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        throw out_of_range("Invalid position! Row and column values must be between 1 and 3. Try again.");
    }

    if (board[row][col].symbol != ' ') {
        throw runtime_error("Invalid move! The selected cell is already occupied. Try again.");
    }

    board[row][col].symbol = symbol;
    return true;
}

bool TicTacToe::isGameOver() {
    for (int row = 0; row < SIZE; ++row) {
        if (board[row][0].symbol != ' ' && board[row][0].symbol == board[row][1].symbol && board[row][0].symbol == board[row][2].symbol) {
            return true;
        }
    }

    for (int col = 0; col < SIZE; ++col) {
        if (board[0][col].symbol != ' ' && board[0][col].symbol == board[1][col].symbol && board[0][col].symbol == board[2][col].symbol) {
            return true;
        }
    }

    if (board[0][0].symbol != ' ' && board[0][0].symbol == board[1][1].symbol && board[0][0].symbol == board[2][2].symbol) {
        return true;
    }

    if (board[0][2].symbol != ' ' && board[0][2].symbol == board[1][1].symbol && board[0][2].symbol == board[2][0].symbol) {
        return true;
    }

    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col].symbol == ' ') {
                return false;
            }
        }
    }
    return true;
}
