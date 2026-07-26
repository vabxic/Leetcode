// reverse inorder
class Solution {
public:
    int runningSum = 0;
    void solve(TreeNode* root) {
        if (!root) { // root == null
            return;
        }
        solve(root->right);
        runningSum += root->val;
        root->val = runningSum;
        solve(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        solve(root);
        return root;
    }
};