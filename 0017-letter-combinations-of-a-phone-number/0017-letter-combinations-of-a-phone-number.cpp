class Solution {
public:
    vector<string> ans;
    string str;

    unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                      {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                      {'8', "tuv"}, {'9', "wxyz"}};
    void backTrack(string& s, int idx) {
        if (idx == s.size()) {
            ans.push_back(str);
            return;
        }
        for (int i = 0; i < mp[s[idx]].size(); ++i) {
            str += mp[s[idx]][i]; // str[i]
            backTrack(s, idx + 1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        backTrack(digits, 0);
        return ans;
    }
};