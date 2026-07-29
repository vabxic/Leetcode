class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int count = 0;
        const size_t n = nums.size();

        while (j < n) {
            if (nums[j] > nums[i]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return count;
    }
};