class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& nums) {
        unordered_map<int, int> winner;
        unordered_map<int, int> loser;

        vector<vector<int>> res(2);

        for (const auto& match : nums) {
            winner[match[0]]++;
            loser[match[1]]++;
        }

        for (auto& k : winner) {
            if (loser[k.first] == 0) {
                res[0].push_back(k.first);
            }
        }

        for (auto& k : loser) {
            if (k.second == 1) {
                res[1].push_back(k.first);
            }
        }

        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());

        return res;
    }
};