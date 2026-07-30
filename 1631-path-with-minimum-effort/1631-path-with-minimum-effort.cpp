class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty()) {

            auto [effort, pos] = pq.top();
            pq.pop();

            int r = pos.first;
            int c = pos.second;

            if (r == n - 1 && c == m - 1)
                return effort;

            if (effort > dist[r][c])
                continue;
            for (auto [dr, dc] : dir) {

                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;

                int newEffort =
                    max(effort, abs(heights[r][c] - heights[nr][nc]));
                if (newEffort < dist[nr][nc]) {

                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, {nr, nc}});
                }
            }
        }
        return 0;
    }
};