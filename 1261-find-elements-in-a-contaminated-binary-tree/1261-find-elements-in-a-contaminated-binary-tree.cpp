class FindElements {
    unordered_set<int> recoverVal;
    void recoverTree(TreeNode* root) {
        if (root == NULL)
            return;
        recoverVal.insert(root->val);
        if (root->left != NULL) {
            root->left->val = 2 * root->val + 1;
            recoverTree(root->left);
        }
        if (root->right != NULL) {
            root->right->val = 2 * root->val + 2;
            recoverTree(root->right);
        }
    }

public:
    FindElements(TreeNode* root) {
        root->val = 0;
        recoverTree(root);
    }

    bool find(int target) { return recoverVal.count(target); }
};
