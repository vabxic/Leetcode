class Solution {
public:
    int minSwaps(vector<int>& nums) {
        auto digit_sum = [](int x) {
            int s = 0;
            for (; x > 0; x /= 10) s += x % 10;
            return s;
        };
        int n = nums.size();
        vector<pair<int, int>> keyed;  // (digit sum, value)
        for (int x : nums) keyed.emplace_back(digit_sum(x), x);
        ranges::sort(keyed);
        unordered_map<int, int> rank; 
        for (int k = 0; k < n; k++) rank[keyed[k].second] = k;
        vector<int> back_pos; 
        for (int x : nums) back_pos.push_back(rank[x]);

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            while (back_pos[i] != i) { 
                int j = back_pos[i];
                swap(back_pos[i], back_pos[j]);
                swaps++;
            }
        }
        return swaps;
    }
};