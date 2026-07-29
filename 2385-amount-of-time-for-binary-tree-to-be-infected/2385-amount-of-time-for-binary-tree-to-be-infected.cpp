// graph + tree

class Solution {
public:
    unordered_map<int, vector<int>> graph;

    void buildGraph(TreeNode* root) {
        if (!root)
            return;

        if (root->left != NULL) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        /*
        adding opposite edges because we want undirect graph
        */
        if (root->right != NULL) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        buildGraph(root->left);
        buildGraph(root->right);
    }
    int amountOfTime(TreeNode* root, int st) {
        buildGraph(root);

        // graph bfs
        constexpr int VAL = 1e5;
        vector<bool> vis(VAL + 1, false);

        queue<int> q;
        q.push(st);
        vis[st] = true;

        int minutePassed = -1;
        while (!q.empty()) {
            ++minutePassed;

            int levelSize = q.size();
            while (levelSize--) {
                int currNode = q.front();
                q.pop();

                for (auto adjNode : graph[currNode]) {
                    if (!vis[adjNode]) {
                        vis[adjNode] = true;
                        q.push(adjNode);
                    }
                }
            }
        }
        return minutePassed;
    }
};