#include <iostream>
using namespace std;

class TicTacToe {
protected:
    char board[3][3];
    char currentPlayer;
    int moves;

public:
    TicTacToe() {
        initializeBoard();
        currentPlayer = 'X';
        moves = 0;
    }

    void initializeBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '1' + i * 3 + j; // Initialize the board with numbers 1 to 9
            }
        }
    }

    void displayBoard() {
        system("cls"); // Clear the screen
        cout << "Tic Tac Toe" << endl;
        cout << "-------------" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " | " << board[i][j]; // Display the game board
            }
            cout << " | " << endl;
            cout << "-------------" << endl;
        }
    }

    bool makeMove(int choice) {
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            return false; // Check if the move is valid
        }

        board[row][col] = currentPlayer; // Make the player's move on the board
        return true;
    }

    bool checkWin() {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true; // Check for a row win
            }
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true; // Check for a column win
            }
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true; // Check for a diagonal win (top-left to bottom-right)
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true; // Check for a diagonal win (top-right to bottom-left)
        }

        return false; // No win yet
    }

    bool checkDraw() {
        return moves == 9; // Check if the game is a draw (all positions filled)
    }

    void togglePlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch the current player
    }

    void playGame() {
        int choice;
        bool gameOver = false;

        while (!gameOver) {
            displayBoard(); // Display the game board

            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> choice;

            if (makeMove(choice)) {
                moves++;
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameOver = true;
                } else if (checkDraw()) {
                    displayBoard();
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                } else {
                    togglePlayer(); // Switch to the other player's turn
                }
            } else {
                cout << "Invalid move. Please try again." << endl; // Handle invalid moves
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame(); // Start the game
    return 0;
}
