// approach 1 level order
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    typedef long long ll;

    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        while (!q.empty()) {
            size_t sz = q.size();
            ll sum = 0;

            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;
                if (curr->left)
                    q.emplace(curr->left);
                if (curr->right)
                    q.emplace(curr->right);
            }
            pq.emplace(sum);

            if (pq.size() > k)
                pq.pop();
        }
        if (pq.size() < k) {
            return -1;
        }
        return pq.top();
    }
};