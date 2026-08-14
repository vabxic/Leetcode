class Solution {
public:
    int maximumLengthSubstring(string s) {
        size_t n = s.size();
        unordered_map<char, int> mp;

        int maxi = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            mp[s[right]]++;

            while (mp[s[right]] > 2) {
                mp[s[left]]--;
                left++;
            }
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};