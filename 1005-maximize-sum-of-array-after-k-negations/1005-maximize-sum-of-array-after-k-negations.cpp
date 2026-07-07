class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int> , greater<int>> pq(nums.begin(),nums.end());

        for(int i=0;i<k;i++)
        {
            int ans = pq.top();
            pq.pop();
            ans*=-1;
            pq.push(ans);
        }
        int sum = 0;
        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }

        return sum;
                }
};
/*
Approach 1
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0;
        while (i < nums.size() && k > 0 && nums[i] < 0) {
            nums[i] = -nums[i];
            i++;
            k--;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int mn = INT_MAX;

        for (int x : nums)
            mn = min(mn, abs(x));

        if (k % 2)
            sum -= 2 * mn;

        return sum;
    }
};
*/