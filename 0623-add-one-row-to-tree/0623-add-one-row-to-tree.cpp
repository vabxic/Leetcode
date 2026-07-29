class Solution {
public:
    TreeNode* leveOrder(TreeNode* root, int data, int levelDepth) {
        if (root == NULL) {
            return NULL;
        }

        int level = 1;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                if (level == levelDepth - 1) {
                    TreeNode* left = curr->left;
                    TreeNode* right = curr->right; //core6

                    curr->left = new TreeNode(data);
                    curr->right = new TreeNode(data);

                    curr->left->left = left;
                    curr->right->right = right;
                } else {
                    if (curr->left)
                        q.push(curr->left);
                    if (curr->right)
                        q.push(curr->right);
                }
            }

            if (level == levelDepth - 1)
                break;

            level++;
        }

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        return leveOrder(root, val, depth);
    }
};