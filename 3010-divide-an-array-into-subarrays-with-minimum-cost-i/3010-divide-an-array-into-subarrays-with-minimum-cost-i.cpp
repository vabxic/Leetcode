class Solution {
public:
    int minimumCost(vector<int>& nums) {
        const size_t n = nums.size();
        int sum = 0;
        sum += nums[0];
        sort(nums.begin() + 1, nums.end());
        sum += nums[1] + nums[2];
        return sum;
    }
};