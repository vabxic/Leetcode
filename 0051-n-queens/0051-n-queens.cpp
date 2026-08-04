class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    int n;

    bool safe(int row, int col) {

        // same col , horizontal
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {

            if (board[i][j] == 'Q')
                return false;
        }

        // upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {

            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void backTrack(int row) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (!safe(row, col)) {
                continue;
            }

            // choose
            board[row][col] = 'Q';

            // explore
            backTrack(row + 1);

            // undo
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int N) {
        n = N;
        board = vector<string>(n, (string(n, '.')));

        backTrack(0);
        return ans;
    }
};