class Solution {
public:
    typedef long long ll;

    long long maximumMedianSum(vector<int>& nums) {
        const size_t n = nums.size();

        sort(nums.rbegin(), nums.rend());

        ll ans = 0;

        for (int i = 1; i < n; i += 2) {
            if (i >= 2 * (n / 3))
                break;

            ans += nums[i];
        }

        return ans;
    }
};