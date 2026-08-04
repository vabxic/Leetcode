class Solution {
public:
    set<vector<int>> st;
    vector<int> curr;

    void backTrack(vector<int>& nums, int idx) {
        size_t n = nums.size();

        if (curr.size() >= 2) {
            st.insert(curr);
        }
        for (int i = idx; i < n; ++i) {

            if (!curr.empty() && nums[i] < curr.back()) {
                continue;
            }
            curr.push_back(nums[i]);

            backTrack(nums, i + 1);

            curr.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTrack(nums, 0);
        return vector<vector<int>>(st.begin(), st.end());
    }
};