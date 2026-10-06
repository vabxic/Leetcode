class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int val = 0) {
        if (!root) return 0;
        val = (val<<1) | root->val;
        int sum = sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
        return (val & -!sum) | sum;
    }
};