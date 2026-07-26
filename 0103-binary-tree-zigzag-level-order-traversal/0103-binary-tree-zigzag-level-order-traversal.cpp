class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root, vector<vector<int>>& nums) {
        if (root == NULL)
            return {};

        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                temp.push_back(curr->val);
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            if ((level & 1) == 0) { // even level
                reverse(temp.begin(), temp.end());
            }
            nums.push_back(temp);
            level++;
        }
        return nums;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        return levelOrder(root, result);
    }
};