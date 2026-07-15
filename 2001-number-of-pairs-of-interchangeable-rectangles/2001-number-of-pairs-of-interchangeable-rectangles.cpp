class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& nums) {
        typedef long long ll;
        const size_t n = nums.size();
        ll count = 0;
        unordered_map<double, int> mp;

        for (int i = 0; i < n; ++i) {
            double val = (double)nums[i][1] / (double)nums[i][0];
            if (mp.find(val) != mp.end()) {
                count += mp[val];
            }
            mp[val]++;
        }

        return count;
    }
};