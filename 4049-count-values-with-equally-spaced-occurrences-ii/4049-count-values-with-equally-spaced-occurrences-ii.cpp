class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        const size_t n = nums.size();
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }
        int ans = 0;
        for (auto& [x, idx] : pos) {
            if (idx.size() < 3)
                continue;
            int d = idx[1] - idx[0];
            bool flag = true;

            for (int i = 2; i < idx.size(); ++i) {
                if (idx[i] - idx[i - 1] != d) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }

        return ans;
    }
};