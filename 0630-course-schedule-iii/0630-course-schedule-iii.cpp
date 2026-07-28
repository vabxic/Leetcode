class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });
        priority_queue<int> pq;
        int sum = 0;

        for (auto x : courses) {
            sum += x[0];
            pq.emplace(x[0]);

            if (sum > x[1]) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
static const auto fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();