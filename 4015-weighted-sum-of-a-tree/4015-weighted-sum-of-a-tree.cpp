class Solution {
public:
    vector<vector<int>> buildTree(vector<int>& parent) {
        int n = parent.size();
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        return tree;
    }

    map<int, vector<int>> bfs(vector<vector<int>>& tree) {
        map<int, vector<int>> mp;

        queue<int> q;
        q.push(0);

        int level = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int node = q.front();
                q.pop();

                mp[level].push_back(node);

                for (int child : tree[node]) {
                    q.push(child);
                }
            }

            level++;
        }

        return mp;
    }

    int height(map<int, vector<int>>& mp) { return mp.rbegin()->first; }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        vector<vector<int>> tree = buildTree(parent);
        map<int, vector<int>> mp = bfs(tree);
        int h = height(mp);

        long long ans = 0;

        for (auto& [depth, nodes] : mp) {
            for (int node : nodes) {
                ans += 1LL * nums[node] * (h - depth + 1);
            }
        }

        return ans;
    }
};