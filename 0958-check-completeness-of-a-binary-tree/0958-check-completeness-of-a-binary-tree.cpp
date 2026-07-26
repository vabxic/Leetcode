class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool nullBeforeNode = false;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL)
                nullBeforeNode = true;
            else {
                if (nullBeforeNode == true)
                    return false;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }
};