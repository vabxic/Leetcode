// DAG problem
//[[1,0]]]
//   v,u
class Solution {
public:
    bool isCycleDirDFS(int curr, vector<bool>& vis, vector<bool>& recPath,
                       vector<vector<int>>& edges) {
        vis[curr] = true;
        recPath[curr] = true;

        for (int i = 0; i < edges.size(); ++i) {
            int v = edges[i][0];
            int u = edges[i][1];

            if (u == curr) {
                if (!vis[v]) {
                    if (isCycleDirDFS(v, vis, recPath, edges)) {
                        return true;
                    }
                } else if (recPath[v]) {
                    return true;
                }
            }
        }
        recPath[curr] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                if (isCycleDirDFS(i, vis, recPath, edges)) {
                    return false;
                }
            }
        }
        return true;
    }
};