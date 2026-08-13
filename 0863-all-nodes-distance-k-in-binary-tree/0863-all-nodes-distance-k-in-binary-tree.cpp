class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;

        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.emplace(root);
        // first BFS for marking parent

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left != NULL) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        q.push(target);
        visited[target] = true;

        int level = 0;
        // second BFS to go upto K level from target node
        while (!q.empty()) {
            size_t sz = q.size();

            if (level == k) {
                break;
            }
            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left != NULL && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right != NULL && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parent[curr] && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
            level++;
        }
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            result.emplace_back(curr->val);
        }
        return result;
    }
};