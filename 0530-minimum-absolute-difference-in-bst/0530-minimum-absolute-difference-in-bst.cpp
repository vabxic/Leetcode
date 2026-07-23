/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = nullptr;
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL)
            return INT_MAX;

        int ans = INT_MAX;
        // INORDER (LNR)
        if (root->left != NULL) {
            int leftMin = getMinimumDifference(root->left); // L
            ans = min(ans, leftMin);
        }
        if (prev != NULL) {
            ans = min(ans, abs(root->val - prev->val)); // N
        }
        prev = root;

        if (root->right != NULL) {
            int rightMin = getMinimumDifference(root->right); // R
            ans = min(ans, rightMin);
        }
        return ans;
    }
};