class Solution {
public:
    void dfs(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& pq) {
        if (!root) return;

        pq.push(root->val);
        dfs(root->left, pq);
        dfs(root->right, pq);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;

        priority_queue<int, vector<int>, greater<int>> pq;
        dfs(root, pq);

        int first = pq.top();

        while (!pq.empty() && pq.top() == first)
            pq.pop();

        return pq.empty() ? -1 : pq.top();
    }
};