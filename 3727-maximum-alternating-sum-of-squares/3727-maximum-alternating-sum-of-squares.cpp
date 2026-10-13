class Solution {
public:
    typedef long long ll;
    long long maxAlternatingSum(vector<int>& nums) {
        ll sum = 0;
        size_t n = nums.size();

        for (int i = 0; i < n; ++i) {
            nums[i] = 1LL * nums[i] * nums[i];
        }
        sort(nums.rbegin(), nums.rend());
        int VAL = n / 2;
        for (int i = 0; i < n - VAL; ++i)
            sum += nums[i];

        for (int i = n - VAL; i < n; ++i)
            sum -= nums[i];

        return sum;
    }
};