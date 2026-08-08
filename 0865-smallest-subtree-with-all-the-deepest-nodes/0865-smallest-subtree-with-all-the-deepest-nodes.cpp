class Solution {
public:
    vector<TreeNode*> deepVal;

    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q)
            return root;

        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);

        if (left && right)
            return root;

        return left != NULL ? left : right;
    }

    void bfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t sz = q.size();
            deepVal.clear();

            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();

                deepVal.push_back(curr);

                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        bfs(root);
        TreeNode* ans = deepVal[0];

        const size_t n = deepVal.size();
        for (int i = 0; i < n; ++i) {
            ans = LCA(root, ans, deepVal[i]);
        }
        return ans;
    }
};