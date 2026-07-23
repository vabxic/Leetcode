/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> res;

    void helper(TreeNode* root) {
        if (root == nullptr)
            return;
        mp[root->val]++;

        helper(root->left);
        helper(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if (!root)
            return res;
        helper(root);

        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(),
             [](auto& a, auto& b) { return b.second < a.second; });
        // for (auto& x : vec) {                                      //debug
        //     cout << x.first << " " << x.second << endl;
        // }
        int mx = vec[0].second;

        for (auto& x : vec) {
            if (x.second == mx)
                res.push_back(x.first);
            else
                break;
        }
        return res;
    }
};