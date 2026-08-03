class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backTrack(int k, int target, int idx) {
        if (curr.size() == k && target == 0) {
            ans.push_back(curr);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = idx; i <= 9; i++) {
            curr.push_back(i);
            backTrack(k, target - i, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backTrack(k, n, 1);
        return ans;
    }
};