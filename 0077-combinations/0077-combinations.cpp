class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;

    void backTract(int idx, int n, int k) {
        if (vec.size() == k) {
            ans.push_back(vec);
            return;
        }

        for (int i = idx; i <= n; ++i) {
            vec.push_back(i);
            backTract(i + 1, n, k);
            vec.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backTract(1, n, k);
        return ans;
    }
};