
/*
sc - o(n)
class Solution {
public:
    vector<int> deep;

    void bfs(TreeNode* root) {
        if (root == NULL)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t sz = q.size();

            deep.clear();
            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();

                deep.push_back(curr->val);
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        bfs(root);
        return accumulate(deep.begin(), deep.end(), 0);
    }
};
*/

// sc - o(1);
class Solution {
public:
    int sum = 0;
    void bfs(TreeNode* root) {
        if (root == NULL)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t sz = q.size();

            sum = 0;
            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        bfs(root);
        return sum;
    }
};