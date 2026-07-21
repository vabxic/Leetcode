class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> a;
        multiset<int> b;

        int n = points.size();
        for (int i = 0; i < n; i++) {
            int point1 = points[i][0];
            int point2 = points[i][1];

            a.insert(point1 + point2);
            b.insert(point1 - point2);
        }

        int ans = 2e9 + 7;

        for (int i = 0; i < n; i++) {
            int point1 = points[i][0];
            int point2 = points[i][1];

            a.erase(a.find(point1 + point2));
            b.erase(b.find(point1 - point2));

            int mn = *a.begin();
            int mpoint1 = *a.rbegin();

            int res = mpoint1 - mn;

            mn = *b.begin();
            mpoint1 = *b.rbegin();

            res = max(res, mpoint1 - mn);

            ans = min(ans, res);
            a.insert(point1 + point2);
            b.insert(point1 - point2);
        }

        return ans;
    }
};