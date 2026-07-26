/*
approach 1

class Solution {
public:
    TreeNode* levelOrder(TreeNode* root) {
        int level = 1;
        if (root == NULL)
            return NULL;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            level++;
        }
        if (level % 2 == 1) { // even and odd
            swap(root->left, root->right);
        }
        return root;
    }
    TreeNode* reverseOddLevels(TreeNode* root) { return levelOrder(root); }
};*/

// approach 2
// perfect bt

using tn = TreeNode*;

class Solution {
public:
    void dfs(tn left, tn right, int level) {
        if (left == NULL || right == NULL)
            return;

        if (level & 1) { // even odd
            swap(left->val, right->val);
        }
        dfs(left->left, right->right, level + 1);
        dfs(left->right, right->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == NULL)
            return NULL;
        dfs(root->left, root->right, 1);
        return root;
    }
};