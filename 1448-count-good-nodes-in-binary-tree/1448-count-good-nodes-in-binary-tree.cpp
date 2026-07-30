class Solution {
public:
    int goodNodes(TreeNode* root) {

        return dfs(root, root->val);
    }
private:
    int dfs(TreeNode* node, int maxi) {
        if (!node) return 0;

        int count = 0;

        if (node->val >= maxi) count = 1;

        maxi = max(maxi, node->val);

        count += dfs(node->left, maxi);
        count += dfs(node->right, maxi);
        return count;
    }
};