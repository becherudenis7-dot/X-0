#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentPlayer = 'X';

void printBoard() {
    cout << "\n";
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            cout << board[r][c];
            if (c < 2) cout << " | ";
        }
        cout << "\n";
        if (r < 2) cout << "---------\n";
    }
    cout << "\n";
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool checkTie() {
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (board[r][c] != 'X' && board[r][c] != 'O') return false;
    return true;
}

void makeMove(int choice) {
    int r = (choice - 1) / 3;
    int c = (choice - 1) % 3;
    if (board[r][c] != 'X' && board[r][c] != 'O')
        board[r][c] = currentPlayer;
    else
        cout << "Spot taken, try again\n";
}

int main() {
    int choice;
    while (true) {
        printBoard();
        cout << "Player " << currentPlayer << " enter a number: ";
        cin >> choice;
        makeMove(choice);
        if (checkWin()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (checkTie()) {
            printBoard();
            cout << "It's a tie!\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}
