class Solution {
public:
    vector<vector<int>> result;

    void traverse(TreeNode* root, int sum, vector<int> temp, int& targetSum) {
        if (root == NULL)
            return;
        sum += root->val;
        temp.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                result.push_back(temp);
            }
            return;
        }
        traverse(root->left, sum, temp, targetSum);
        traverse(root->right, sum, temp, targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;
        traverse(root, sum, temp, targetSum);

        return result;
    }
};