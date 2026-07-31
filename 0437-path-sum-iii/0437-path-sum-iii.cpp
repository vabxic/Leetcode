class Solution {
public:
    int count = 0;

    void helper(TreeNode* root, long long sum, int targetSum) {
        if (root == NULL)
            return;

        sum += root->val;

        if (sum == targetSum)
            count++;

        helper(root->left, sum, targetSum);
        helper(root->right, sum, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;

        helper(root, 0LL, targetSum);

        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return count;
    }
};