class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int chain = 1;
        const size_t n = pairs.size();

        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        int prevFirst = pairs[0][0];
        int prevLast = pairs[0][1];
        for (int i = 1; i < n ; ++i){
            if (pairs[i][0] > prevLast){
                chain ++;
                prevFirst = pairs[i][0];
                prevLast = pairs[i][1];
            }
        }
        return chain;
    }
};