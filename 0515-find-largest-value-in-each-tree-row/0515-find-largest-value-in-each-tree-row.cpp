class Solution {
public:
    vector<int> levelOrder(TreeNode* root, vector<int>& nums) {
        if (root == NULL)
            return {};

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int maxi = INT_MIN;
            int size = q.size();
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                maxi = max(maxi, curr->val);
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            nums.push_back(maxi);
        }
        return nums;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        return levelOrder(root, result);
    }
};