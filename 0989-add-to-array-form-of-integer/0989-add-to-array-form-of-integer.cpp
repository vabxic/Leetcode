class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int i = nums.size() - 1;

        while (i >= 0 || k) {
            if (i >= 0) k += nums[i];
            if (i >= 0) nums[i] = k % 10;
            else nums.insert(nums.begin(), k % 10);
            k /= 10;
            i--;
        }

        return nums;
    }
};