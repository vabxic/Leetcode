class Solution {
public:
    unordered_map<int, int> mp;

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);

        int sum = root->val + leftSum + rightSum;
        mp[sum]++;

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);

        int mx = 0;
        for (auto &[sum, freq] : mp) {
            mx = max(mx, freq);
        }

        vector<int> res;
        for (auto &[sum, freq] : mp) {
            if (freq == mx)
                res.push_back(sum);
        }

        return res;
    }
};