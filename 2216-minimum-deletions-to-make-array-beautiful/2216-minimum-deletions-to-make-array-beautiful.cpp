class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int d = 0;
        size_t n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            int newIdx = i - d;
            if ((newIdx % 2 == 0) && nums[i] == nums[i + 1]) {
                d++;
            }
        }
        return ((n - d) % 2 == 0) ? d : d + 1;
    }
};