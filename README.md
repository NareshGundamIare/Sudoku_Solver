# Sudoku_Solver

This Sudoku solver is a simple console application written in C that solves Sudoku puzzles.

## Features

- Input from User: Allows users to input Sudoku puzzles directly into the program.
- Backtracking Algorithm: Uses a backtracking algorithm to find the solution for the Sudoku puzzle.
- Error Handling: Provides warnings for invalid input and alerts the user if no solution exists for the given puzzle.

## Usage

1. Inputting a Sudoku Puzzle:
   - Run the program and follow the prompts to input the Sudoku puzzle row by row.
   - Use the numbers 1-9 to represent filled cells and 0 or any other invalid input to represent empty cells.
   - Each row should contain 9 numbers separated by spaces.

2. Solving the Puzzle:
   - After inputting the entire puzzle, the program attempts to solve it.
   - If a solution is found, the solved Sudoku grid is displayed.
   - If no solution exists, the program displays a message indicating that no solution was found.

## Example


Enter the Sudoku puzzle (use 0 for empty cells):
Enter numbers for row 1: 5 3 0 0 7 0 0 0 0
Enter numbers for row 2: 6 0 0 1 9 5 0 0 0
Enter numbers for row 3: 0 9 8 0 0 0 0 6 0
Enter numbers for row 4: 8 0 0 0 6 0 0 0 3
Enter numbers for row 5: 4 0 0 8 0 3 0 0 1
Enter numbers for row 6: 7 0 0 0 2 0 0 0 6
Enter numbers for row 7: 0 6 0 0 0 0 2 8 0
Enter numbers for row 8: 0 0 0 4 1 9 0 0 5
Enter numbers for row 9: 0 0 0 0 8 0 0 7 9

Solution:
 5 3 4 6 7 8 9 1 2
 6 7 2 1 9 5 3 4 8
 1 9 8 3 4 2 5 6 7
 8 5 9 7 6 1 4 2 3
 4 2 6 8 5 3 7 9 1
 7 1 3 9 2 4 8 5 6
 9 6 1 5 3 7 2 8 4
 2 8 7 4 1 9 6 3 5
 3 4 5 2 8 6 1 7 9


## Author
NareshGundamIare
