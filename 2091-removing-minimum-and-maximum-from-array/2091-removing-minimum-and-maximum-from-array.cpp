class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();

        int first = min(minIdx, maxIdx);
        int last = max(minIdx, maxIdx);

        return min({
            last + 1,            // front
            n - first,           // back
            first + 1 + n - last // both
        });
    }
};