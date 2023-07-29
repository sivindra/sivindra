#include <iostream>
#include <vector>

using namespace std;

const int BOARD_SIZE = 3;
const char PLAYER_1_SYMBOL = 'X';
const char PLAYER_2_SYMBOL = 'O';

// Function to initialize the game board
vector<vector<char> > initializeBoard() {
    return vector<vector<char> >(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));
}

// Function to display the game board
void displayBoard(const vector<vector<char> >& board) {
    cout << "-------------\n";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n-------------\n";
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char> >& board, char playerSymbol) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol)
            return true;

        if (board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol)
            return true;
    }

    if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol)
        return true;

    if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)
        return true;

    return false;
}

// Function to check if the game ended in a draw
bool checkDraw(const vector<vector<char> >& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Function to get player's move
void getPlayerMove(int& row, int& col) {
    cout << "Enter row (1-3) and column (1-3) to place your symbol: ";
    cin >> row >> col;
    row--; // Convert to 0-based indexing
    col--;
}

// Function to validate player's move
bool isValidMove(const vector<vector<char> >& board, int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ');
}

// Function to clear the board for a new game
void clearBoard(vector<vector<char> >& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";

    char playAgain = 'Y';
    while (playAgain == 'Y' || playAgain == 'y') {
        vector<vector<char> > board = initializeBoard();
        int currentPlayer = 1;
        int movesLeft = BOARD_SIZE * BOARD_SIZE;

        while (true) {
            displayBoard(board);

            int row, col;
            getPlayerMove(row, col);

            if (!isValidMove(board, row, col)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board[row][col] = (currentPlayer == 1) ? PLAYER_1_SYMBOL : PLAYER_2_SYMBOL;
            movesLeft--;

            if (checkWin(board, currentPlayer == 1 ? PLAYER_1_SYMBOL : PLAYER_2_SYMBOL)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (movesLeft == 0) {
                displayBoard(board);
                cout << "It's a draw!\n";
                break;
            }

            currentPlayer = 3 - currentPlayer; // Switch player (1 -> 2 or 2 -> 1)
        }

        cout << "Play again? (Y/N): ";
        cin >> playAgain;

        if (playAgain != 'Y' && playAgain != 'y') {
            cout << "Thank you for playing Tic-Tac-Toe!\n";
        } else {
            clearBoard(board);
        }
    }

    return 0;
}
