class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        const size_t n = nums.size();
        priority_queue<int> pq(nums.begin(), nums.end());
        long long sum = 0;
        while (k > 0) {
            int num = pq.top();
            pq.pop();
            if (mul > 1)
                sum += 1LL * num * mul;
            else
                sum += num;

            mul--;
            k--;
        }
        return sum;
    }
};