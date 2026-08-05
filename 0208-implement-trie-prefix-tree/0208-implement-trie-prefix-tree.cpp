class TrieNode {
public:
    TrieNode* child[26];
    bool isWord;

    TrieNode() {
        isWord = false;
        for (auto& x : child) {
            x = nullptr;
        }
    }
};
class Trie {
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (auto& a : word) {
            int idx = a - 'a';

            if (!node->child[idx]) {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->isWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->child[idx] == nullptr) {
                return false;
            } else {
                node = node->child[idx];
            }
        }
        return node->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (node->child[idx] == nullptr) {
                return false;
            } else {
                node = node->child[idx];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */