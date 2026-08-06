class Solution {
public:
    vector<double> ans;

    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;

            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left != NULL)
                    q.push(curr->left);

                if (curr->right != NULL)
                    q.push(curr->right);
            }

            double avg = (double)accumulate(level.begin(), level.end(), 0LL) /
                         level.size();
            ans.push_back(avg);
        }
    }

    vector<double> averageOfLevels(TreeNode* root) {
        bfs(root);
        return ans;
    }
};