/*
o(1) space

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            int prev = (level % 2 == 0) ? INT_MIN : INT_MAX;

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                if ((level & 1) == 0) { // Even level
                    if ((curr->val & 1) == 0 || curr->val <= prev)
                        return false;
                } else { // Odd level
                    if ((curr->val & 1) == 1 || curr->val >= prev)
                        return false;
                }

                prev = curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            level++;
        }

        return true;
    }
};
*/


//o(n) space
class Solution {
public:
    bool levelOrder(TreeNode* root) {
        if ((root->val & 1) == 0)
            return false;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            vector<int> vec;
            int size = q.size();

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                vec.push_back(curr->val);

                if (curr->left != NULL)
                    q.push(curr->left);

                if (curr->right != NULL)
                    q.push(curr->right);
            }

            if ((level & 1) == 0) { // even level
                if (vec.size() == 1 && (vec[0] & 1) == 0)
                    return false;

                for (int i = 1; i < vec.size(); ++i) {
                    if ((vec[i] & 1) == 0)
                        return false;

                    if (vec[i] <= vec[i - 1])
                        return false;
                }
            } else { // odd level
                if (vec.size() == 1 && (vec[0] & 1) == 1)
                    return false;

                for (int i = 1; i < vec.size(); ++i) {
                    if ((vec[i] & 1) == 1)
                        return false;

                    if (vec[i] >= vec[i - 1])
                        return false;
                }
            }
            level++;
        }
        return true;
    }

    bool isEvenOddTree(TreeNode* root) {
        return levelOrder(root);
    }
};
