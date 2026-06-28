
/*approach 1 1900ms;
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    string findCommonResponse(vector<vector<string>>& res) {
        const size_t n = res.size();
        unordered_map<string, int> mp;

        for (int i = 0; i < n; ++i) {
            unordered_set<string> st(res[i].begin(), res[i].end());
            vector<string> temp(st.begin(), st.end());

            for (int j = 0; j < temp.size(); ++j) {
                mp[temp[j]]++;
            }
        }

        vector<pair<string, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        });

        return vec[0].first;
    }
};
*/
class Solution {
public:
    string findCommonResponse(vector<vector<string>>& res) {
        const size_t n = res.size();
        unordered_map<string, int> mp;

        for (int i = 0; i < n; ++i) {
            unordered_set<string> st(res[i].begin(), res[i].end());
            vector<string> temp(st.begin(), st.end());

            for (int j = 0; j < temp.size(); ++j) {
                mp[temp[j]]++;
            }
        }

        string ans = "";
        int mx = 0;
        // one pass
        for (auto& it : mp) {
            if (it.second > mx ||
                (it.second == mx && (ans.empty() || it.first < ans))) {
                mx = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};