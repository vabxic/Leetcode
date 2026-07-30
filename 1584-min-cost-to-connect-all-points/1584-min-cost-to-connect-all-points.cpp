/*prims*/

class Solution {
public:
    using P = pair<int, int>;
    using V = vector<P>;

    int manDist(vector<vector<int>>& nums, int p1, int p2) {
        return abs(nums[p1][0] - nums[p2][0]) + abs(nums[p1][1] - nums[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& nums) {
        const size_t n = nums.size();

        priority_queue<P, V, greater<P>> pq;
        vector<bool> mstSet(n, false);
        int minCost = 0;

        pq.push({0, 0});
        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (mstSet[node])
                continue;
            mstSet[node] = true;
            minCost += wt;

            for (int i = 0; i < n; ++i) {
                if (!mstSet[i]) {
                    int edgeWt = manDist(nums, node, i);
                    pq.push({edgeWt, i});
                }
            }
        }
        return minCost;
    }
};