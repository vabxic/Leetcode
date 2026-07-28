class Solution {
public:
    string smallestPalindrome(string s) {
        size_t n = s.length();

        string half = s.substr(0, n / 2);
        sort(half.begin(), half.end());

        string res = half;
        if (n & 1) {
            res += s[n / 2];
        }

        string rev = half;
        reverse(rev.begin(), rev.end());
        res += rev;

        return res;
    }
};