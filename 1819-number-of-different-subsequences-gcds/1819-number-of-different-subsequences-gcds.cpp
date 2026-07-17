class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        const size_t n = nums.size();

        int count = 0;
        int MX = *max_element(nums.begin(), nums.end());
        unordered_set<int> seen(nums.begin(), nums.end());

        for (int i = 1; i <= MX; ++i) {
            int currGCD = 0;
            for (int j = i; j <= MX; j += i) {
                if (seen.count(j)) {
                    currGCD = __gcd(currGCD, j);
                }
                if (currGCD == i) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};