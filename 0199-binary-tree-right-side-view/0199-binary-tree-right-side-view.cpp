class Solution {
public:
    vector<int> leveOrder(TreeNode* root, vector<int>& nums) {
        if (root == NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                if (size == 0) {
                    nums.push_back(curr->val);
                }
                /*
                for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();                             //iter
                q.pop();
                if (i == size - 1) result.push_back(node->val);
                */
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }
        return nums;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        return leveOrder(root, result);
    }
};