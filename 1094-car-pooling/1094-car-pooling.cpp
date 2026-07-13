class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const size_t n = trips.size();
        vector<pair<int, int>> temp;

        for (unsigned i = 0; i < n; i++) {
            temp.push_back({trips[i][1], trips[i][0]});
            temp.push_back({trips[i][2], -trips[i][0]});
        }
        sort(temp.begin(), temp.end(), [](auto& a, auto& b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        });

        int res = 0;
        for (unsigned i = 0; i < temp.size(); i++) {
            res += temp[i].second;
            if (res > capacity) {
                return false;
            }
        }
        return true;
    }
};