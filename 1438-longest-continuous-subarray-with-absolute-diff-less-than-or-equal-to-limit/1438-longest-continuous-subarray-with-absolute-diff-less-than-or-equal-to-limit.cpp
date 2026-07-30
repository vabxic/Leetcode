class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        deque<int> decreasingQ;
        deque<int> increasingQ;
        int ans = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            int num = nums[right];

            while (!decreasingQ.empty() && num > decreasingQ.back()) {
                decreasingQ.pop_back();
            }
            decreasingQ.push_back(num);

            while (!increasingQ.empty() && num < increasingQ.back()) {
                increasingQ.pop_back();
            }
            increasingQ.push_back(num);

            while (decreasingQ.front() - increasingQ.front() > limit) {
                if (decreasingQ.front() == nums[left]) {
                    decreasingQ.pop_front();
                }
                if (increasingQ.front() == nums[left]) {
                    increasingQ.pop_front();
                }
                ++left;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};