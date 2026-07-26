class Solution {
public:
    int runningSum = 0;
    void reverseInorder(TreeNode* root) {
        if (!root)
            return;

        reverseInorder(root->right);
        runningSum += root->val;
        root->val = runningSum;
        reverseInorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        reverseInorder(root);
        return root;
    }
};