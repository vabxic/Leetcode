class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root; // base case
        }

        queue<Node*> q;
        q.push(root);
        q.push(NULL); // mark end of level

        Node* prev = NULL;

        while (q.size() > 0) {
            Node* curr = q.front();
            q.pop();

            if (curr == NULL) {
                prev = NULL;
                if (q.empty()) {
                    break;
                }
                q.push(NULL);
            } else {
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
                if (prev != NULL) {
                    prev->next = curr;
                }
                prev = curr;
            }
        }
        return root;
    }
};