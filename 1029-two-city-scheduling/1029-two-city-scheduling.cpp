class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> diff;
        size_t n = costs.size();
        int minCost = 0;

        for (int i = 0; i < n; ++i) {
            minCost += costs[i][0];
            diff.push_back(costs[i][1] - costs[i][0]);
        }
        sort(diff.begin(), diff.end());

        for (int i = 0; i < n / 2; ++i) {
            minCost += diff[i];
        }
        return minCost;
    }
};