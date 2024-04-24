#include <stdio.h>
#include <stdbool.h>
#define N 10 // Define the maximum size of the chessboard

int count = 0;

void printBoard(int board[][N], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int board[][N], int row, int col, int size) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < size; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueen(int board[][N], int col, int size) {
    if (col >= size) {
        count++;
        printf("Solution %d:\n", count);
        printBoard(board, size);
        printf("\n");
        return true;
    }

    for (int i = 0; i < size; i++) {
        if (isSafe(board, i, col, size)) {
            board[i][col] = 1;
        solveNQueen(board, col + 1, size);
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}

int main() {
    int size;
    printf("Enter the size of the board: ");
    scanf("%d", &size);

    int board[N][N];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
    solveNQueen(board, 0, size);

    printf("Total number of calls to the queen procedure: %d\n", count);

    return 0;
}
