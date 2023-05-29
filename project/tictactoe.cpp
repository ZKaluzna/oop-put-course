#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class BoardCell {
public:
    char symbol;
};
// a class representing a single cell on the board, it contains only one symbol field which holds an 'X', 'O' or blank space character

class TicTacToe {
public:
    static const int SIZE = 3; // constant board size
    BoardCell board[SIZE][SIZE]; //an array of BoardCells of size SIZE x SIZE

public:
    TicTacToe() {
        // 
        for (int row = 0; row < SIZE; ++row) {
            for (int col = 0; col < SIZE; ++col) {
                board[row][col].symbol = ' ';
            }
        }
    }
// class constructor initializing the board by setting the symbol as ' 'for all board's cells
    void displayBoard() {
        // Displaying the board with row and column numbers
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

    bool makeMove(int row, int col, char symbol) {
      // Adjusting row and column values by 1
        --row;
        --col;

      // Checking if the move is valid
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col].symbol != ' ') {
            return false;
        }
      
      // Making the move if it is valid
        board[row][col].symbol = symbol;
        return true;
    }

    bool isGameOver() {    // Checking if any of the game-ending conditions are met

        // Checking rows
        for (int row = 0; row < SIZE; ++row) {
            if (board[row][0].symbol != ' ' && board[row][0].symbol == board[row][1].symbol && board[row][0].symbol == board[row][2].symbol) {
                return true;
            }
        }

        // Checking columns
        for (int col = 0; col < SIZE; ++col) {
            if (board[0][col].symbol != ' ' && board[0][col].symbol == board[1][col].symbol && board[0][col].symbol == board[2][col].symbol) {
                return true;
            }
        }

        // Checking diagonals
        if (board[0][0].symbol != ' ' && board[0][0].symbol == board[1][1].symbol && board[0][0].symbol == board[2][2].symbol) {
            return true;
        }

        if (board[0][2].symbol != ' ' && board[0][2].symbol == board[1][1].symbol && board[0][2].symbol == board[2][0].symbol) {
            return true;
        }

        // Checking for a tie = none of the conditions decisiving victory are met
        for (int row = 0; row < SIZE; ++row) {
            for (int col = 0; col < SIZE; ++col) {
                if (board[row][col].symbol == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    TicTacToe game;

    int row, col;
    char symbol = 'X';

    while (!game.isGameOver()) {
        game.displayBoard();

        cout << "Player " << symbol << ", enter your move (row and column): ";
        cin >> row >> col;

        if (!game.makeMove(row, col, symbol)) {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Switching to the other player after a valid move
        symbol = (symbol == 'X') ? 'O' : 'X';
    }

    game.displayBoard();

    char winnerSymbol = ' ';

    // Checking rows
    for (int row = 0; row < TicTacToe::SIZE; ++row) {
        if (game.board[row][0].symbol != ' ' && game.board[row][0].symbol == game.board[row][1].symbol && game.board[row][0].symbol == game.board[row][2].symbol) {
            winnerSymbol = game.board[row][0].symbol;
            break;
        }
    }

    // Checking columns
    for (int col = 0; col < TicTacToe::SIZE; ++col) {
        if (game.board[0][col].symbol != ' ' && game.board[0][col].symbol == game.board[1][col].symbol && game.board[0][col].symbol == game.board[2][col].symbol) {
            winnerSymbol = game.board[0][col].symbol;
            break;
        }
    }

    // Checking diagonals
    if (game.board[0][0].symbol != ' ' && game.board[0][0].symbol == game.board[1][1].symbol && game.board[0][0].symbol == game.board[2][2].symbol) {
        winnerSymbol = game.board[0][0].symbol;
    }

    if (game.board[0][2].symbol != ' ' && game.board[0][2].symbol == game.board[1][1].symbol && game.board[0][2].symbol == game.board[2][0].symbol) {
        winnerSymbol = game.board[0][2].symbol;
    }

    if (winnerSymbol != ' ') {
        cout << "Player " << winnerSymbol << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
