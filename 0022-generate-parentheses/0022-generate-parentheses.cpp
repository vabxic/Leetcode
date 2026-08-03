class Solution {
public:
    vector<string> ans;
    string str;
    void backTrack(int n, int open, int close) {
        if (open > n || close > open) { // pruning
            return;
        }
        if (str.size() == 2 * n) {
            ans.push_back(str);
            return;
        }
        // add '('
        str.push_back('(');
        backTrack(n, open + 1, close);
        str.pop_back();

        // add ')'
        str.push_back(')');
        backTrack(n, open, close + 1);
        str.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        backTrack(n, 0, 0);
        return ans;
    }
};