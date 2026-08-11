class Solution {
public:
    int sum = 0;

    int bfs(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftDiff = bfs(root->left);
        int rightDiff = bfs(root->right);

        sum += abs(leftDiff - rightDiff);

        return root->val + leftDiff + rightDiff;
    }

    int findTilt(TreeNode* root) {
        bfs(root);
        return sum;
    }
};