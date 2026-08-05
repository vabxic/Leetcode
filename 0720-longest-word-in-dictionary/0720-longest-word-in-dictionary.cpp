class Solution {
public:
    class TrieNode {
    public:
        bool isWord;
        TrieNode* child[26];

        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; ++i) {
                child[i] = nullptr;
            }
        }
    };
    TrieNode* root;
    string ans = "";

    void insert(string word) {
        TrieNode* curr = root;

        for (auto& ch : word) {
            int idx = ch - 'a';

            if (curr->child[idx] == nullptr) {
                curr->child[idx] = new TrieNode();
            }
            curr = curr->child[idx];
        }
        curr->isWord = true;
    }
    void dfs(TrieNode* root, string& temp) {
        if (root == nullptr)
            return;

        for (int i = 0; i < 26; ++i) {
            if (root->child[i] != nullptr && root->child[i]->isWord) {
                temp.push_back((char)i + 'a');
                if (temp.size() > ans.size()) {
                    ans = temp;
                }
                dfs(root->child[i], temp);
                temp.pop_back();
            }
        }
    }
    string longestWord(vector<string>& words) {
        root = new TrieNode();
        for (string& word : words) {
            insert(word);
        }
        string temp = "";
        dfs(root, temp);
        return ans;
    }
};