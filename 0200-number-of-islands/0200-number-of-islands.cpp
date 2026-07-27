/*
graph dfs
    src = i,j
                  (i-1,j)
                    |
      (i,j-1)  ---- 1 ---- (i,j+1)
                    |
                  (i+1,j)
*/
void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid,int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != '1') {
        return;
    }
    vis[i][j] = true;
    dfs(i - 1, j, vis, grid, n, m); // top
    dfs(i + 1, j, vis, grid, n, m); // bottom
    dfs(i, j - 1, vis, grid, n, m); // left
    dfs(i, j + 1, vis, grid, n, m); // right
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        size_t n = grid.size();
        size_t m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, vis, grid, n, m);
                    island++;
                }
            }
        }
        return island;
    }
};