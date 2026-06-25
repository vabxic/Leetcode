class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for (int j = i; j < n; j++) {
                mp[nums[j]]++;

                if (mp[target] > (j - i + 1) / 2) {
                    count++;
                }
            }
        }

        return count;
    }
};