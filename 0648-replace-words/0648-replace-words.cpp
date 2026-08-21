
class Trie {
public:
    Trie* children[26];
    bool isEnd;

    Trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Solution {
public:
    Trie* root;

    Solution() {
        root = new Trie();
    }

    void insert(string word) {
        Trie* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new Trie();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }

    string search(string word) {
        Trie* node = root;
        string result;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                return word;
            }
            result += c;
            if (node->children[i]->isEnd) {
                return result;
            }
            node = node->children[i];
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string word : dictionary) {
            insert(word);
        }

        stringstream ss(sentence);
        string word, result;
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += search(word);
        }
        return result;
    }
};
/*class Solution {
public:
    string replaceWords(vector<string>& dict, string sent) {
        unordered_set<string> s(dict.begin(), dict.end());
        stringstream ss(sent);

        vector<string> temp;
        string word, res;

        while (ss >> word) {
            temp.push_back(word);
        }

        for (auto& t : temp) {
            int i = 0;

            while (i++ <= t.size()) {
                string curr = t.substr(0, i);
                if (s.find(curr) != s.end()) {
                    res += curr + " ";
                    break;
                }
                if (i == t.size())
                    res += curr + " ";
            }
        }
        res.erase(res.size() - 1);
        return res;
    }
};*/