class Solution {
public:
    int ans = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        if (root->left && root->left->val == root->val) l++;
        else l = 0;

        if (root->right && root->right->val == root->val) r++;
        else r = 0;

        ans = max(ans, l + r);
        return max(l, r);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};