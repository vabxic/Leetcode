class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>res;
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=nums[0]; i<=nums[nums.size()-1]; i++){
            if(i != nums[j]){
                res.push_back(i);
            } else {
                j++;
            }   
        }
        return res;
    }
};