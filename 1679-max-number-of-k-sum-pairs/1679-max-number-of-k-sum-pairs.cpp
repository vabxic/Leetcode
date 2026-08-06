class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        const size_t n = nums.size();
        unordered_map<int, int> mp;

        int pair = 0;
        for (int i = 0; i < n; ++i) {
            int need = k - nums[i];

            if (mp[need] > 0) {
                pair++;
                --mp[need];
            } else {
                ++mp[nums[i]];
            }
        }
        return pair;
    }
};