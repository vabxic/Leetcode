using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")
static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const size_t n = nums.size();
        int ans = 0 , left = 0;

        unordered_map<int,int>mp;
        for (int right = 0; right < n; right++){
            mp[nums[right]]++;

            while (mp[nums[right]] > k){
                mp[nums[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
        }return ans;
    }
};