#include <iostream>
using namespace std;

bool isSafe(int sudoku[9][9], int row, int col, int digit) {

    // checking if digit is present in column
    for (int j = 0; j < 9; j++) {
        if (sudoku[j][col] == digit) {
            return false;
        }
    }

    // checking if digit is present in row
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == digit) {
            return false;
        }
    }

    // checking if digit is present in same 3 x 3 grid
    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;

    for (int i = sr; i < sr + 3; i++) {
        for (int j = sc; j < sc + 3; j++) {
            if (sudoku[i][j] == digit) {
                return false;
            }
        }
    }

    return true;
}


bool sudokuSolver(int sudoku[9][9], int row, int col) {

    // base case
    if (row == 9) {
        return true;
    }

    // calculate next cell
    int newRow = row;
    int newCol = col + 1;

    if (col + 1 == 9) {
        newRow = row + 1;
        newCol = 0;
    }

    // if cell is already filled
    if (sudoku[row][col] != 0) {
        return sudokuSolver(sudoku, newRow, newCol);
    }

    // try digits 1 to 9
    for (int digit = 1; digit <= 9; digit++) {

        if (isSafe(sudoku, row, col, digit)) {

            sudoku[row][col] = digit;

            // recursion
            if (sudokuSolver(sudoku, newRow, newCol)) {
                return true;
            }

            // backtracking
            sudoku[row][col] = 0;
        }
    }

    return false;
}


void printSudoku(int sudoku[9][9]) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {

    int sudoku[9][9] = {
        {0, 0, 8, 0, 0, 0, 0, 0, 0},
        {4, 9, 0, 1, 5, 7, 0, 0, 2},
        {0, 0, 3, 0, 0, 4, 1, 9, 0},
        {1, 8, 5, 0, 6, 0, 0, 2, 0},
        {0, 0, 0, 0, 2, 0, 0, 6, 0},
        {9, 6, 0, 4, 0, 5, 3, 0, 0},
        {0, 3, 0, 0, 7, 2, 0, 0, 4},
        {0, 4, 9, 0, 3, 0, 0, 5, 7},
        {8, 2, 7, 0, 0, 9, 0, 1, 3}
    };

    if (sudokuSolver(sudoku, 0, 0)) {
        cout << "Solution exists" << endl;
        printSudoku(sudoku);
    }
    else {
        cout << "Solution doesn't exist" << endl;
    }

    return 0;
}