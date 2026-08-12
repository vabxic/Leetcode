class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& nums) {
        const size_t n = nums.size();

        sort(nums.begin(), nums.end());
        int mx = 0;
        for (int i = 1; i < n; ++i) {
            mx = max(mx, nums[i] - nums[i - 1] - 1);
        }
        mx = max((nums[0] - bottom), mx);
        mx = max((top - nums[n - 1]), mx);
        return mx;
    }
};