#include <iostream>
using namespace std;

int n = 4;
int board[10][10];

// check if safe
bool isSafe(int row, int col) {

    // check column
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 1)
            return false;
    }

    // check left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1)
            return false;
    }

    // check right diagonal
    for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 1)
            return false;
    }

    return true;
}

// solve using backtracking
bool solve(int row) {

    if(row == n)
        return true;

    for(int col = 0; col < n; col++) {

        if(isSafe(row, col)) {
            board[row][col] = 1;

            if(solve(row + 1))
                return true;

            // backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    if(solve(0)) {
        cout << "Solution:\n";

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists";
    }

    return 0;
}
