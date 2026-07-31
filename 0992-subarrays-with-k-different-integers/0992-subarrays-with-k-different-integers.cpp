class Solution {
public:
    int Atmost(vector<int> & nums,int k){
        size_t n = nums.size();
        int left = 0,count = 0;
        unordered_map<int,int>mp;

        for (int right = 0 ; right < n ; right++){
            mp[nums[right]]++;
            while (mp.size() > k){
                //shrink
                mp[nums[left]]--;
                if (mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            count += right-left+1;
        }return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return Atmost(nums,k) - Atmost(nums,k-1);
    }
};