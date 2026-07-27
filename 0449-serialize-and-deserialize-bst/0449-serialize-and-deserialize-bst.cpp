/*class Codec {
public:
    // Encodes to string
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL)
                s += "#,"; // s.append("#,")
            else {
                s += to_string(curr->val) + ',';
            }
            if (curr != NULL) {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        cout << s;
        return s;
    }

    // Decodes to tree
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return NULL;
        stringstream s(data);

        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // left child
            if (getline(s, str, ',')) {
                if (str != "#") {
                    curr->left = new TreeNode(stoi(str));
                    q.push(curr->left);
                }
            }

            // right child
            if (getline(s, str, ',')) {
                if (str != "#") {
                    curr->right = new TreeNode(stoi(str));
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};
*/
class Codec {
public:
    // Serialize
    string serialize(TreeNode* root) {
        if (!root)
            return "";

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            s += to_string(curr->val) + ",";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        return s;
    }

    // Insert
    TreeNode* insert(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);

        if (val < root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }

    // Deserialize
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        while (getline(ss, str, ',')) {
            if (!str.empty())
                insert(root, stoi(str));
        }

        return root;
    }
};