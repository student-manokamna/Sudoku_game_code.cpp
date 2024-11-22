#include <iostream>
using namespace std;

const int GRID_SIZE = 9;

void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    cout << "+-------+-------+-------+\n";
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (col % 3 == 0) cout << "| ";
            if (grid[row][col] == 0)
                cout << ". ";
            else
                cout << grid[row][col] << " ";
        }
        cout << "|\n";
        if ((row + 1) % 3 == 0) cout << "+-------+-------+-------+\n";
    }
}

bool isSafe(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num) {
    for (int x = 0; x < GRID_SIZE; x++) {
        if (grid[row][x] == num) return false;
    }
    for (int x = 0; x < GRID_SIZE; x++) {
        if (grid[x][col] == num) return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid)) {
                            return true;
                        }
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE];

    cout << "+-----------------------------------------+\n";
    cout << "|           Welcome to Sudoku Solver      |\n";
    cout << "+-----------------------------------------+\n\n";

    cout << "Enter the Sudoku grid (use 0 for empty cells):\n";
    cout << "Input each row with 9 numbers separated by spaces.\n\n";

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "\nInitial Sudoku Grid:\n";
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku Grid:\n";
        printGrid(grid);
    } else {
        cout << "\nNo solution exists for the given Sudoku grid.\n";
    }

    cout << "\n+-----------------------------------------+\n";
    cout << "|       Thank you for using Sudoku Solver! |\n";
    cout << "+-----------------------------------------+\n";

    return 0;
}
