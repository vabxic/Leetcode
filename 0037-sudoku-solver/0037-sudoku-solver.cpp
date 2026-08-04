class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {

        // Row
        for (int j = 0; j < 9; j++)
            if (board[row][j] == ch)
                return false;

        // Column
        for (int i = 0; i < 9; i++)
            if (board[i][col] == ch)
                return false;

        // 3x3 Box
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;

        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (board[i][j] == ch)
                    return false;
            }
        }

        return true;
    }

    bool backtrack(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] != '.')
                    continue;

                for (char ch = '1'; ch <= '9'; ch++) {

                    if (!isValid(board, i, j, ch))
                        continue;

                    // Choose
                    board[i][j] = ch;

                    // Explore
                    if (backtrack(board))
                        return true;

                    // Undo
                    board[i][j] = '.';
                }
                       
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};