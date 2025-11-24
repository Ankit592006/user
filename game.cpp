#include <iostream>
using namespace std;

#define N 4

int grid[N][N] = {
    {0, 0, 2, 0},
    {0, 0, 0, 1},
    {1, 0, 0, 0},
    {0, 4, 0, 0}
};

bool isSafe(int row, int col, int num) {
    // check row
  for (int x = 0; x < N; x++) {
    if (grid[row][x] == num || grid[x][col] == num)
        return false;
}


    // check 2×2 box
    int startRow = row - row % 2;
    int startCol = col - col % 2;
    for (int r = 0; r < 2; r++)
        for (int c = 0; c < 2; c++)
            if (grid[startRow + r][startCol + c] == num)
                return false;

    return true;
}

bool solveSudoku() {
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 4; num++) {
                    if (isSafe(row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku())
                            return true;
                        grid[row][col] = 0; // backtrack
                    }
                }
                return false;
            }
    return true;
}

int main() {
    if (solveSudoku()) {
        cout << "Solved Sudoku:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists";
    }
    return 0;
}
