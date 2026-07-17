class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        int mx = *max_element(nums1.begin(), nums1.end());
        unordered_map<int, int> freq;
        for (int x : nums2)
            freq[x * k]++;

        vector<int> cnt(mx + 1, 0);

        for (auto& [val, f] : freq) {
            for (int multiple = val; multiple <= mx; multiple += val)
                cnt[multiple] += f;
        }

        int ans = 0;
        for (int x : nums1)
            ans += cnt[x];

        return ans;
    }
};