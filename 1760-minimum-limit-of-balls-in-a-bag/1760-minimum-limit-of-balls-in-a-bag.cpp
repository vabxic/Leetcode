class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        const size_t n = nums.size();
        int st = 1;
        int end = *max_element(nums.begin(), nums.end());

        while (st < end) {
            int mid = st + (end - st) / 2;
            int ops = 0;

            for (int num : nums) {
                ops += (num - 1) / mid;
                if (ops > maxOperations)
                    break;
            }
            if (ops <= maxOperations) {
                end = mid;
            } else {
                st = mid + 1;
            }
        }
        return st;
    }
};