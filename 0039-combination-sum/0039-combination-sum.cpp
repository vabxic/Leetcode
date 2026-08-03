class Solution {
public:
    vector<vector<int>> vec;
    vector<int> curr;

    void backTrack(vector<int>& nums, int target, int idx) {
        if (target == 0) {
            vec.push_back(curr);
            return;
        }

        if (target < 0)
            return;

        for (int i = idx; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            backTrack(nums, target - nums[i], i); // reuse same element
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backTrack(nums, target, 0);
        return vec;
    }
};