class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (auto a : nums) {
            int x = a;
            int digitsum = 0;
            while (x) {
                digitsum += x % 10;
                x /= 10;
            }
            mp[digitsum].push_back(a);
        }
        int mx = -1;
        for (auto& [k, v] : mp) {
            if (v.size() > 1) {
                sort(v.rbegin(), v.rend());
                mx = max(mx, v[0] + v[1]);
            }
        }
        return mx;
    }
};