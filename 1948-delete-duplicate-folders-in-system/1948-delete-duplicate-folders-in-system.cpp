class Solution {
    struct TrieNode {
        map<string, TrieNode*> child;
        string serial = "";
        bool deleted = false;
    };

    TrieNode* root = new TrieNode();
    unordered_map<string, int> mp;

    //build Trie
    void insert(vector<string>& path) {
        TrieNode* cur = root;

        for (string& folder : path) {
            if (!cur->child.count(folder)) {
                cur->child[folder] = new TrieNode();
            }

            cur = cur->child[folder];
        }
    }

    // subtree signature
    string dfs(TrieNode* node) {
        string s = "";

        for (auto& [name, child] : node->child) {
            s += name;
            s += "(";
            s += dfs(child);
            s += ")";
        }

        node->serial = s;

        if (!s.empty())
            mp[s]++;

        return s;
    }

    // mark duplicate folders
    void mark(TrieNode* node) {
        for (auto& [name, child] : node->child) {
            if (mp[child->serial] > 1) {
                child->deleted = true;
            }

            mark(child);
        }
    }

    void build(TrieNode* node,
               vector<string>& path,
               vector<vector<string>>& ans) {

        for (auto& [name, child] : node->child) {

            if (child->deleted)
                continue;

            path.push_back(name);
            ans.push_back(path);

            build(child, path, ans);

            path.pop_back();
        }
    }

public:
    vector<vector<string>> deleteDuplicateFolder(
        vector<vector<string>>& paths) {

        for (auto& path : paths) {
            insert(path);
        }

        dfs(root);
        mark(root);
        vector<vector<string>> ans;
        vector<string> path;

        build(root, path, ans);

        return ans;
    }
};