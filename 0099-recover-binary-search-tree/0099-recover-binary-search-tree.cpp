//[1,3,8,6,4,9]
class Solution {
public:
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);
        if (prev != NULL && prev->val > root->val) {
            if (first == NULL) {
                first = prev;        // faulty pairs [8,6] & [6,4], we have to swap 8 and 4 
            }
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};