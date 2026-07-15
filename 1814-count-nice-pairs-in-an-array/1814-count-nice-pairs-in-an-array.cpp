class Solution {
public:
    int rev(int n) {
        int num = 0;
        while (n > 0) {
            int digit = n % 10;
            num = num * 10 + digit;
            n /= 10;
        }
        return num;
    }
    int countNicePairs(vector<int>& nums) {
        const size_t n = nums.size();
        constexpr static int MOD = 1e9 + 7;

        int pair = 0;
        unordered_map<int, int> mp;
        for (int x : nums) {
            if (mp.count(x - rev(x))) {
                pair = (pair + mp[x - rev(x)]) % MOD;
            }
            mp[x - rev(x)]++;
        }
        return pair;
    }
};