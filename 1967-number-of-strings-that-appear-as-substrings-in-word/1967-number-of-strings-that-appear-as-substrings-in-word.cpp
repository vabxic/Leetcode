class Solution {
public:
    int numOfStrings(vector<string>& pat, string word) {
        int n = pat.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (word.find(pat[i]) != string::npos) {
                count++;
            }
        }
        return count;
    }
};