class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        typedef long long ll;
        const size_t n = nums.size();
        constexpr static int N = 1e5;

        vector<ll> divisorSum(N + 1, 0);
        vector<int> divisorCount(N + 1, 0);

        for (unsigned i = 1; i <= N; ++i) {
            for (unsigned j = i; j <= N; j += i) {
                divisorCount[j]++;
                divisorSum[j] += i;
            }
        }
        int ans = 0;
        for (auto x : nums) {
            if (divisorCount[x] == 4) {
                ans += divisorSum[x];
            }
        }
        return (int)ans;
    }
};