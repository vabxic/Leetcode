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
    priority_queue<int, vector<int>, greater<int>> pq;
    void helper(TreeNode* root) {
        if (root == nullptr)
            return;

        helper(root->left);
        pq.emplace(root->val);
        helper(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        helper(root);
        while (k--) {
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};