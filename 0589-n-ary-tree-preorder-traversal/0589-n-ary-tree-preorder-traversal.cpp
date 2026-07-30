class Solution {
public:
    vector<int> helper(Node* root, vector<int>& result) {
        // N.L.R
        if (root == NULL)
            return {};
        result.push_back(root->val);

        for (Node* node : root->children) {
            helper(node, result);
        }
        return result;
    }
    vector<int> preorder(Node* root) {
        vector<int> nums;
        return helper(root, nums);
    }
};