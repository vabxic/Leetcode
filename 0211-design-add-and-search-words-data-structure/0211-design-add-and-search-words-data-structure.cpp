class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

TrieNode* root;

class WordDictionary {
public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* Node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (Node->child[idx] == NULL) {
                Node->child[idx] = new TrieNode();
            }

            Node = Node->child[idx];
        }

        Node->isEnd = true;
    }

    bool dfs(TrieNode* Node, string& word, int i) {
        if (i == word.size()) {
            return Node->isEnd;
        }

        if (word[i] != '.') {
            int idx = word[i] - 'a';

            if (Node->child[idx] == NULL) {
                return false;
            }

            return dfs(Node->child[idx], word, i + 1);
        }

        // word[i] == '.'
        for (int j = 0; j < 26; j++) {
            if (Node->child[j] != NULL) {
                if (dfs(Node->child[j], word, i + 1)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool search(string word) { return dfs(root, word, 0); }
};