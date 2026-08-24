class Solution {
public:
    typedef long long ll;
    static constexpr int MOD = 1e5;

    vector<bool> isPrime;

    void seive(int n) {
        isPrime.assign(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }
    }

    ll splitArray(vector<int>& nums) {
        size_t n = nums.size();
        seive(n);

        ll sumA = 0, sumB = 0;

        for (int i = 0; i < n; ++i) {
            if (isPrime[i])
                sumA += nums[i];
            else
                sumB += nums[i];
        }

        return abs(sumA - sumB);
    }
};