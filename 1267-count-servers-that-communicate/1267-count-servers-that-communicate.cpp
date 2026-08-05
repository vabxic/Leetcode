class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        size_t m = grid.size();
        size_t n = grid[0].size();

        vector<int> rowCount(m, 0);
        vector<int> columnCount(n, 0);
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    columnCount[j]++;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (rowCount[i] > 1 || columnCount[j] > 1)
                        count++;
                }
            }
        }
        return count;
    }
};