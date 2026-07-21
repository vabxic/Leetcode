class Solution {
public:
    int wateringPlants(vector<int>& nums, int capacity) {
        const size_t n = nums.size();
        int step = 0;
        int org = capacity;
        for (int i = 0; i < n; ++i) {
            if (capacity < nums[i]) {
                step += 2 * i; // jaane ka i and aane ka i;
                capacity = org;
            }
            capacity -= nums[i];
            step++;
        }
        return step;
    }
};