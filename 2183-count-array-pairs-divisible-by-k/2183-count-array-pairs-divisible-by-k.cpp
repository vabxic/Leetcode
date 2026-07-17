typedef long long ll;
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        const size_t n = nums.size();
        unordered_map<ll, ll> gcdCount;
        ll ans = 0;

        for (unsigned i = 0; i < n; ++i) {
            ll currGCD = __gcd(nums[i], k);
            ll need = k / currGCD;

            for (auto x : gcdCount) {
                if (x.first % need == 0) {
                    ans += x.second;
                }
            }
            gcdCount[currGCD]++;
        }
        return ans;
    }
};