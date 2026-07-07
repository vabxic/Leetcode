class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0;
        while (i < nums.size() && k > 0 && nums[i] < 0) {
            nums[i] = -nums[i];
            i++;
            k--;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int mn = INT_MAX;

        for (int x : nums)
            mn = min(mn, abs(x));

        if (k % 2)
            sum -= 2 * mn;

        return sum;
    }
};