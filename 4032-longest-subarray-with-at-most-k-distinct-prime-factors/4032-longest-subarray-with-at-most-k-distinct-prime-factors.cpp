class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        const int MAX = 100000;

        // Smallest prime factor
        vector<int> spf(MAX + 1);
        for (int i = 0; i <= MAX; i++) spf[i] = i;

        for (int i = 2; i * i <= MAX; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAX; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        // Prime factors
        vector<vector<int>> factors(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];
                factors[i].push_back(p);

                while (x % p == 0)
                    x /= p;
            }
        }

        vector<int> freq(MAX + 1, 0);

        int l = 0;
        int distinct = 0;
        int ans = 0;

        for (int r = 0; r < n; r++) {

            for (int p : factors[r]) {
                if (freq[p]++ == 0)
                    distinct++;
            }

            while (distinct > k) {
                for (int p : factors[l]) {
                    if (--freq[p] == 0)
                        distinct--;
                }
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};