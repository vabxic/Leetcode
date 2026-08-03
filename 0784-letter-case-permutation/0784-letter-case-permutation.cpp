class Solution {
public:
    vector<string> ans;
    void backTrack(int idx, string& s) {
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        }
        if (isdigit(s[idx])) {
            backTrack(idx + 1, s);
            return;
        }
        // to lower
        s[idx] = tolower(s[idx]);
        backTrack(idx + 1, s);

        // to upper
        s[idx] = toupper(s[idx]);
        backTrack(idx + 1, s);
    }
    vector<string> letterCasePermutation(string s) {
        backTrack(0,s);
        return ans;
    }
};