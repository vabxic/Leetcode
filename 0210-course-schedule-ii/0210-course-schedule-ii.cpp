class Solution {
public:
    bool isCycleDirDFS(int curr, vector<bool>& vis, vector<bool>& recPath,
                       vector<vector<int>>& edges) {
        vis[curr] = true;
        recPath[curr] = true;

        for (int i = 0; i < edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];

            if (u == curr) {
                if (!vis[v]) {
                    if (isCycleDirDFS(v, vis, recPath, edges))
                        return true;
                } else if (recPath[v]) {
                    return true;
                }
            }
        }

        recPath[curr] = false;
        return false;
    }

    void dfs(int curr, vector<bool>& vis, stack<int>& s,
             vector<vector<int>>& edges) {

        vis[curr] = true;

        for (int i = 0; i < edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];

            if (u == curr) {
                if (!vis[v])
                    dfs(v, vis, s, edges);
            }
        }

        s.push(curr);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {

        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);

        // Detect cycle
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (isCycleDirDFS(i, vis, recPath, edges))
                    return {};
            }
        }

        // Reset visited for Topological Sort
        fill(vis.begin(), vis.end(), false);

        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, vis, s, edges);
        }

        vector<int> ans;

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
static const auto fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();