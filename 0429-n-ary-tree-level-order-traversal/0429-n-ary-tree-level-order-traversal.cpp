class Solution {
public:
    vector<vector<int>> N_aryLevelOrder(Node* root, vector<vector<int>>& nums) {
        if (root == NULL)
            return {};
        queue<Node*> q;

        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;

            while (size--) {
                Node* curr = q.front();
                q.pop();
                temp.push_back(curr->val);

                for (auto child : curr->children) {
                    q.push(child);
                }
            }
            nums.push_back(temp);
        }
        return nums;
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        return N_aryLevelOrder(root, result);
    }
};