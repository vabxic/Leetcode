class Solution {
public:
    int count(vector<vector<char>>& board, int row, int col) {
        int cnt = 0;

        int rowDir[] = {0, -1, 0, 1};
        int colDir[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int nrow = row + rowDir[i];
            int ncol = col + colDir[i];

            while (nrow >= 0 && nrow < 8 && ncol >= 0 && ncol < 8) {
                
                if (board[nrow][ncol] == 'B') {
                    break;
                }

                if (board[nrow][ncol] == 'p') {
                    cnt++;
                    break;
                }

                nrow += rowDir[i];
                ncol += colDir[i];
            }
        }

        return cnt;
    }

    int numRookCaptures(vector<vector<char>>& board) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    return count(board, i, j);
                }
            }
        }

        return 0;
    }
};