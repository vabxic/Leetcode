class Solution {
public:
    void dfs(int src, vector<vector<int>>& rooms, vector<bool>& vis) {
        vis[src] = true;

        for (int key : rooms[src]) {
            if (!vis[key]) {
                dfs(key, rooms, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const size_t n = rooms.size();
        vector<bool> vis(n, false);

        dfs(0, rooms, vis);

        for (int i = 0; i < n; ++i) {
            if (!vis[i])
                return false;
        }
        return true;
    }
};