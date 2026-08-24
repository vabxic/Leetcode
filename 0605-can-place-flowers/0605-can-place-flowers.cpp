class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int k = nums.size();

        for (int i = 0; i < k && n; i++) {
            if (nums[i] == 0 && (i == 0 || nums[i - 1] == 0) &&
                (i == k - 1 || nums[i + 1] == 0)) {
                nums[i] = 1;
                n--;
                i++;
            }
        }

        return n == 0;
    }
};