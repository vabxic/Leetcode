class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        typedef long long ll;
        const size_t n = nums.size();
        sort(nums.begin(), nums.end());

        ll pairs = 0;
        for (int i = 0; i < n; ++i) {
            int idx =
                lower_bound(nums.begin() + 1 + i, nums.end(), lower - nums[i]) -
                nums.begin();
            int x = idx - 1 - i;

            idx =
                upper_bound(nums.begin() + 1 + i, nums.end(), upper - nums[i]) -
                nums.begin();
            int y = idx - 1 - i;

            pairs += (y - x);
        }
        return pairs;
    }
};