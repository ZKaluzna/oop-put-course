#include <iostream>
#include "TicTacToe.h"

int main() {
    TicTacToe game;

    int row, col;
    char symbol = 'X';

    try {
        while (!game.isGameOver()) {
            game.displayBoard();

            cout << "Player " << symbol << ", enter your move (row and column): ";
            cin >> row >> col;

            try {
                if (!game.makeMove(row, col, symbol)) {
                    continue;
                }
            } catch (const out_of_range& ex) {
                cout << ex.what() << endl;
                continue;
            } catch (const runtime_error& ex) {
                cout << ex.what() << endl;
                continue;
            }

            symbol = (symbol == 'X') ? 'O' : 'X';
        }

        game.displayBoard();

        char winnerSymbol = ' ';

        for (int row = 0; row < TicTacToe::SIZE; ++row) {
            if (game.board[row][0].symbol != ' ' && game.board[row][0].symbol == game.board[row][1].symbol && game.board[row][0].symbol == game.board[row][2].symbol) {
                winnerSymbol = game.board[row][0].symbol;
                break;
            }
        }

        for (int col = 0; col < TicTacToe::SIZE; ++col) {
            if (game.board[0][col].symbol != ' ' && game.board[0][col].symbol == game.board[1][col].symbol && game.board[0][col].symbol == game.board[2][col].symbol) {
                winnerSymbol = game.board[0][col].symbol;
                break;
            }
        }

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
    } catch (const exception& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}
