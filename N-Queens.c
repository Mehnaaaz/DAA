#include <stdio.h>
#include <stdbool.h>

// Function to print the chessboard
void printSolution(int board[][10], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(board[i][j] ? "Q " : ". ");
        }
        printf("\n");
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[][10], int row, int col, int N) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Backtracking function to solve N-Queens
bool solveNQueensUtil(int board[][10], int row, int N) {
    if (row >= N) {
        return true; // All queens are placed
    }

    // Try placing a queen in all columns of the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the next queen
            if (solveNQueensUtil(board, row + 1, N)) {
                return true;
            }

            // Backtrack if placing queen at (row, col) doesn't lead to a solution
            board[row][col] = 0;
        }
    }

    return false; // No valid position found
}

// Function to solve the N-Queens problem
void solveNQueens(int N) {
    int board[10][10] = {0}; // Initialize the board with 0s

    if (solveNQueensUtil(board, 0, N)) {
        printSolution(board, N); // Print the solution if found
    } else {
        printf("Solution does not exist\n");
    }
}

int main() {
    int N;

    // Input the size of the board
    printf("Enter the value of N: ");
    scanf("%d", &N);

    solveNQueens(N); // Solve the N-Queens problem

    return 0;
}
