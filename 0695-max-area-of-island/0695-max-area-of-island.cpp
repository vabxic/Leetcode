class Solution {
public:
    int dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& grid,
            int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] ||
            grid[i][j] != 1) {
            return 0;
        }
        int area = 1;
        vis[i][j] = true;
        area += dfs(i - 1, j, vis, grid, n, m); // top
        area += dfs(i + 1, j, vis, grid, n, m); // bottom
        area += dfs(i, j - 1, vis, grid, n, m); // left
        area += dfs(i, j + 1, vis, grid, n, m); // right

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        size_t n = grid.size();
        size_t m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int maxi = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    maxi = max(maxi, dfs(i, j, vis, grid, n, m));
                }
            }
        }
        return maxi;
    }
};