class Solution {
public:
    void DFS(int i, vector<vector<int>>& nums, vector<bool>& vis) {
        vis[i] = true;

        for (int j = 0; j < nums.size(); ++j) {
            if (!vis[j] && nums[i][j] == 1) {
                DFS(j, nums, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numOfProvinces = 0;
        const size_t n = isConnected.size();
        vector<bool> vis(n, false);

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                DFS(i, isConnected, vis);
                numOfProvinces++;
            }
        }
        return numOfProvinces;
    }
};