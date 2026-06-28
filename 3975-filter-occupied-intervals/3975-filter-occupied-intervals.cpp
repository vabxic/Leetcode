class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& nums,
                                                int st, int end) {
        const size_t n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        res.push_back(nums[0]);

        for (int i = 1; i < n; ++i) {
            auto& last = res.back();
            auto& num = nums[i];

            if (num[0] <= last[1] + 1) {
                last[1] = max(last[1], num[1]);
            } else {
                res.push_back(num);
            }
        }
        vector<vector<int>> ans;
        for (auto& it : res) {
            int l = it[0], r = it[1];

            if (r < st || l > end) {
                ans.push_back({l, r});
            } else {
                if (l < st) {
                    ans.push_back({l, st - 1});
                }
                if (r > end) {
                    ans.push_back({end + 1, r});
                }
            }
        }
        return ans;
    }
};