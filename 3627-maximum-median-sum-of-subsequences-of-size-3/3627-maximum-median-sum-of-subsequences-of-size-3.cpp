class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        size_t n = nums.size();

        int left = 0;
        int right = n - 1;

        long long sum = 0;
        sort(nums.begin(), nums.end());
        while(right > left){

            int val = right - 1;
            sum += nums[val];
            left++;
            right -= 2;
        }
        return sum;
    }
};