class Solution {
public:
    int maxProduct(vector<int>& nums) {
        make_heap(nums.begin(), nums.end());

        int a = nums.front();
        pop_heap(nums.begin(), nums.end());
        nums.pop_back();
        int b = nums.front();
        return (a-1)*(b-1);
    }
};