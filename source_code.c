#include <stdio.h>
#include <stdbool.h>

#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            printf("%2d", grid[row][col]);
        printf("\n");
    }
}

// Function to check if a given number can be placed in the specified cell
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is already present in the row or column
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;

    // Check if the number is already present in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (grid[r + startRow][c + startCol] == num)
                return false;

    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // If there is no unassigned cell, the puzzle is solved
    bool isComplete = true;
    for (row = 0; row < N && isComplete; row++)
        for (col = 0; col < N && isComplete; col++)
            if (grid[row][col] == 0)
                isComplete = false;

    if (isComplete)
        return true; // Puzzle solved

    // Find an unassigned cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                // Try placing numbers from 1 to 9
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        // Place the number in the cell
                        grid[row][col] = num;

                        // Recursively solve the rest of the puzzle
                        if (solveSudoku(grid))
                            return true; // Puzzle solved successfully

                        // If placing the number doesn't lead to a solution, backtrack
                        grid[row][col] = 0;
                    }
                }
                return false; // No valid number found for this cell
            }
        }
    }

    return false; // No unassigned cell found
}

// Function to validate user input
bool isValidInput(int num) {
    return (num >= 0 && num <= 9);
}

int main() {
    int grid[N][N];

    // Input Sudoku puzzle from the user
    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for (int row = 0; row < N; row++) {
        printf("Enter numbers for row %d: ", row + 1);
        for (int col = 0; col < N; col++) {
            int num;
            scanf("%d", &num);
            if (!isValidInput(num)) {
                printf("Warning: Invalid input! Please enter numbers between 0 and 9.\n");
                printf("Input at row %d, column %d will be considered as an empty cell.\n", row + 1, col + 1);
                num = 0; // Treat invalid input as an empty cell
            }
            grid[row][col] = num;
        }
    }

    if (solveSudoku(grid))
        printGrid(grid);
    else
        printf("No solution exists! Enter correct values\n");

    return 0;
}
