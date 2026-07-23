/*
approach 1
unordered_map


class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.emplace(root);

        int level = 1;
        unordered_map<int, int> mp;

        while (!q.empty()) {
            size_t sz = q.size();
            int sum = 0;

            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            mp[level] = sum;
            level++;
        }
        int ansLevel = 0;
        int mx = INT_MIN;

        for (int i = 1; i < level; i++) {
            if (mp[i] > mx) {
                mx = mp[i];
                ansLevel = i;
            }
        }

        return ansLevel;
    }
};
*/

//approach 2

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.emplace(root);

        int level = 1;
        int ans = 1;
        int mx = INT_MIN;

        while (!q.empty()) {
            size_t sz = q.size();
            int sum = 0;

            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
           if (sum > mx){
                mx = sum;
                ans  = level;

            }
            level++;
        }
        return ans;
    }
};
