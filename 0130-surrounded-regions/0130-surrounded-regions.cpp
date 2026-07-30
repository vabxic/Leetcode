class Solution {
public:
    void DFS(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
            return;
        board[i][j] = '#';

        DFS(board, i + 1, j, m, n);
        DFS(board, i - 1, j, m, n);
        DFS(board, i, j + 1, m, n);
        DFS(board, i, j - 1, m, n);
    }
    void solve(vector<vector<char>>& board) {
        const size_t m = board.size();
        const size_t n = board[0].size();

        // first and last col
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                DFS(board, i, 0, m, n);
            if (board[i][n - 1] == 'O')
                DFS(board, i, n - 1, m, n);
        }

        // first and last row
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                DFS(board, 0, j, m, n);
            if (board[m - 1][j] == 'O')
                DFS(board, m - 1, j, m, n);
        }
        /*
        // First Row
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                DFS(board, 0, j, m, n);
        }

        // Last Row
        for (int j = 0; j < n; j++) {
            if (board[m - 1][j] == 'O')
                DFS(board, m - 1, j, m, n);
        }

        // First Column
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                DFS(board, i, 0, m, n);
        }

        // Last Column
        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'O')
                DFS(board, i, n - 1, m, n);
        }
        */
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};