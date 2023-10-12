class Solution {
private:
    bool isInBox(vector<vector<char>> &v, char n, int row, int col) {
        int boxStartRow = (row / 3) * 3;
        int boxStartCol = (col / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (v[boxStartRow + i][boxStartCol + j] == n) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isInRow(vector<vector<char>> &v, char n, int row) {
        for (int col = 0; col < 9; col++) {
            if (v[row][col] == n) {
                return true;
            }
        }
        return false;
    }

    bool isInCol(vector<vector<char>> &v, char n, int col) {
        for (int row = 0; row < 9; row++) {
            if (v[row][col] == n) {
                return true;
            }
        }
        return false;
    }

    bool solve(vector<vector<char>> &v) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (v[row][col] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (!isInRow(v, c, row) && !isInCol(v, c, col) && !isInBox(v, c, row, col)) {
                            v[row][col] = c;
                            if (solve(v)) {
                                return true;
                            }
                            v[row][col] = '.'; // Undo the choice if it doesn't lead to a solution.
                        }
                    }
                    return false;
                }
            }
        }
        return true; // No empty cell found, the puzzle is solved.
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
