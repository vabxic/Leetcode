// approach 1
//  self made

static const auto fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    TreeNode* InorderSuccessor(TreeNode* root) {
        while (root != NULL && root->left != NULL)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL) {
                return root->right;
            } else if (root->right == NULL) {
                return root->left;
            } else {
                TreeNode* IS = InorderSuccessor(root->right);
                root->val = IS->val;
                root->right = deleteNode(root->right, IS->val);
            }
        }

        return root;
    }

    TreeNode* inorder(TreeNode* root, int low, int high) {
        if (root == NULL)
            return NULL;

        root->left = inorder(root->left, low, high);

        if (root->val < low || root->val > high) {
            root = deleteNode(root, root->val);
            return inorder(root, low, high);
        }

        root->right = inorder(root->right, low, high);

        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return inorder(root, low, high);
    }
};

/* approach 2
 optimal
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL)
            return NULL;

        if (root->val < low)
            return trimBST(root->right, low, high);

        if (root->val > high)
            return trimBST(root->left, low, high);

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
*/
