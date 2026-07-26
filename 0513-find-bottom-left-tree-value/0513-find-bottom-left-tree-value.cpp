class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int temp = size;
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                if (size == temp - 1) {
                    ans = curr->val;
                }
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }
        return ans;
    }
};