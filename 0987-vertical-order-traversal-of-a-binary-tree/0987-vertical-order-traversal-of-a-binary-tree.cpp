class Solution {
public:
    vector<vector<int>> ans;

    void bfs(TreeNode* root) {
        if (root == NULL)
            return;

        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, vector<pair<int, int>>> mp;

        // {node, {HD, row}}
        q.push({root, {0, 0}});

        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            int currHD = q.front().second.first;
            int currRow = q.front().second.second;
            q.pop();

            mp[currHD].push_back({currRow, curr->val});

            if (curr->left != NULL) {
                q.push({curr->left, {currHD - 1, currRow + 1}});
            }

            if (curr->right != NULL) {
                q.push({curr->right, {currHD + 1, currRow + 1}});
            }
        }

        for (auto p : mp) {
            sort(p.second.begin(), p.second.end());
            vector<int> curr;

            for (auto x : p.second) {
                curr.push_back(x.second);
            }

            ans.push_back(curr);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        bfs(root);
        return ans;
    }
};