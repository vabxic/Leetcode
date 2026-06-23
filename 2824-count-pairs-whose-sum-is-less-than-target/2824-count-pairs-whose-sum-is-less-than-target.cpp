class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int pair = 0;
        const size_t n = nums.size();

        for (int i = 0; i < n; ++i){
            for (int j = i+1; j < n ; ++j){
                if (nums[i]+nums[j] < target)pair++;
            }
        }return pair;
    } 
};