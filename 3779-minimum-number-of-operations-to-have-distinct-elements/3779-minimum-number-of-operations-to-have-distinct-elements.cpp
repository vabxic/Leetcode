class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        set<int> st;
        int i = n - 1;

        while (i >= 0) {
            if (st.count(nums[i])) {
                break;
            } else {
                st.insert(nums[i]);
            }
            i--;
        }
        return (i + 3) / 3;
    }
};