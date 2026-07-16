class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        typedef long long ll;
        const size_t n = nums.size();
        int mx = 0;

        for (unsigned i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);
            // mx = *max_element(nums.begin(), nums.begin() + i + 1);
            nums[i] = gcd(nums[i], mx);
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;

        ll res = 0;

        while (i < j) {
            res += gcd(nums[i], nums[j]);
            i++;
            j--;
        }
        return res;
    }
};