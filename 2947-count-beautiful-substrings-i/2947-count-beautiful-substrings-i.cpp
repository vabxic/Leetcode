class Solution {
public:
    string vowel = "aeiou";
    int beautifulSubstrings(string s, int k) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            int vow = 0, con = 0;
            for (int j = i; j < s.size(); ++j) {
                if (vowel.find(s[j]) != string::npos)
                    vow++;
                else {
                    con++;
                }
                if (vow == con && (vow * con) % k == 0)
                    ans++;
            }
        }
        return ans;
    }
};