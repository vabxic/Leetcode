typedef long long ll;
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        ll mx = *max_element(nums1.begin(), nums1.end());
        unordered_map<ll, ll> freq;
        for (ll x : nums2)
            freq[x * k]++;

        vector<ll> cnt(mx + 1, 0);

        for (auto& [val, f] : freq) {
            for (ll multiple = val; multiple <= mx; multiple += val)
                cnt[multiple] += f;
        }

        ll ans = 0;
        for (ll x : nums1)
            ans += cnt[x];

        return ans;
    }
};