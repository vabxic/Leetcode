class Solution {
public:
    int minimumRefill(vector<int>& nums, int capA, int capB) {
        int refill = 0;
        const size_t n = nums.size();
        int orgA = capA;
        int orgB = capB;
        int i = 0, j = n - 1;

        while (i < j) {
            if (capA < nums[i]) {
                capA = orgA;
                refill++;
            }
            if (capB < nums[j]) {
                capB = orgB;
                refill++;
            }
            capA -= nums[i];
            capB -= nums[n - i - 1];
            i++;
            j--;
        }
        if (i == j && nums[i] > capA && nums[j] > capB)
            refill++;
        return refill;
    }
};