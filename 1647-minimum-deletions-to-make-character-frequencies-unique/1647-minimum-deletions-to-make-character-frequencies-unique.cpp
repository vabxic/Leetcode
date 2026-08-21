class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);

        int ans = 0;
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        for (int i = 1; i < 26; ++i) {
            while (freq[i] > 0 && freq[i] >= freq[i - 1]) {
                freq[i]--;
                ans++;
            }
        }

        return ans;
    }
};