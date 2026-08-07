// floydd warshall
class Solution {
public:
    vector<vector<int>> dist;
    const int INF = 1e9;
    void buildGraph(int n, vector<vector<int>>& edges) {
        dist.assign(n, vector<int>(n, INF));

        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }
    }

    void floyddWarshall() {
        size_t n = dist.size();

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] == INF || dist[k][j] == INF)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int countReachable(int city, int distanceThreshold) {
        int count = 0;
        for (int j = 0; j < dist.size(); ++j) {

            if (j != city && dist[city][j] <= distanceThreshold)
                count++;
        }
        return count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        buildGraph(n, edges);
        floyddWarshall();

        int ans = -1;
        int mn = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int count = countReachable(i, distanceThreshold);
            if (count <= mn) {
                mn = count;
                ans = i;
            }
        }
        return ans;
    }
};