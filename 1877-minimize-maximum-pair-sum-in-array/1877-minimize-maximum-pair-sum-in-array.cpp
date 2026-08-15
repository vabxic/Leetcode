class Solution {
public:
    int minPairSum(vector<int>& nums) {
        size_t n = nums.size();

        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        int maxi = INT_MIN;

        while (i < j) {
            int sum = 0;

            sum += nums[i] + nums[j];
            maxi = max(maxi, sum);
            i++;
            j--;
        }
        return maxi;
    }
};