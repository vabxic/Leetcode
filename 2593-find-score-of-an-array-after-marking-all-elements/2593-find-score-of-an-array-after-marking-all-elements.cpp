class Solution {
public:
    typedef long long ll;
    typedef pair<int, int> P;

    long long findScore(vector<int>& nums) {
        const size_t n = nums.size();

        priority_queue<P, vector<P>, greater<P>> pq;
        ll score = 0;

        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
        }

        vector<bool> temp(n, false);

        while (!pq.empty()) {

            auto [x, j] = pq.top();
            pq.pop();

            if (temp[j])
                continue;
            score += x;
            temp[j] = true;

            if (j - 1 >= 0)
                temp[j - 1] = true;

            if (j + 1 < n)
                temp[j + 1] = true;
        }

        return score;
    }
};