class TrieNode {
public:
    TrieNode* child[10];

    TrieNode() {
        for (int i = 0; i < 10; i++)
            child[i] = NULL;
    }
};

void insert(TrieNode* root, int num) {
    string s = to_string(num);
    TrieNode* curr = root;

    for (char c : s) {
        int digit = c - '0';

        if (curr->child[digit] == NULL)
            curr->child[digit] = new TrieNode();

        curr = curr->child[digit];
    }
}

void dfs(TrieNode* root, int num, vector<int>& ans) {
    if (num != -1)
        ans.push_back(num);

    for (int i = 0; i <= 9; i++) {
        if (root->child[i] != NULL) {
            if (num == -1)
                dfs(root->child[i], i, ans);
            else
                dfs(root->child[i], num * 10 + i, ans);
        }
    }
}

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        TrieNode* root = new TrieNode();

        for (int i = 1; i <= n; i++)
            insert(root, i);

        vector<int> ans;
        dfs(root, -1, ans);

        return ans;
    }
};