class Solution {
public:
    void levelOrder(TreeNode* root, vector<vector<int>>& nums) {
        if (root == NULL)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left != NULL)
                    q.push(curr->left);

                if (curr->right != NULL)
                    q.push(curr->right);
            }

            nums.push_back(level);
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;

        levelOrder(root, res);
        reverse(res.begin(), res.end());

        return res;
    }
};