class Solution {
public:
    bool isPossible(vector<vector<int>>& nums, int mid) {
        for (int i = 0; i < nums.size(); ++i) {
            if (mid < nums[i][1])
                return false;

            mid -= nums[i][0];
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int st = 0, end = 1e9;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (isPossible(nums, mid))
                end = mid;
            else
                st = mid + 1;
        }

        return st;
    }
};