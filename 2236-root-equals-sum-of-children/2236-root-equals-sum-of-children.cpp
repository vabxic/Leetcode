class Solution {
public:
    int sum(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return root->val + sum(root->left) + sum(root->right);
    }

    bool checkTree(TreeNode* root) {
        return root->val == sum(root->left) + sum(root->right);
    }
};