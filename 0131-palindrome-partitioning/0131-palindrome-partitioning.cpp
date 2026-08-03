class Solution {
    vector<vector<string>> ans;
    vector<string> curr;

private:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

public:
    void backTrack(string& s, int idx) {
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i < s.size(); ++i) {
            if (!isPalindrome(s, idx, i))
                continue;

            curr.push_back(s.substr(idx, i - idx + 1));
            backTrack(s, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        backTrack(s, 0);
        return ans;
    }
};