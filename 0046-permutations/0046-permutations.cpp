/*apporoach 1 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return res;
    }
};
*/

// approach 2
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")
static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
private:
    int fact(int n) {
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            ans *= i;
        }
        return ans;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int step = fact(n);

        for (int i = 0; i < step; i++) {
            res.push_back(nums);
            int pivot = -1;

            for (int j = n - 2; j >= 0; j--) {
                if (nums[j] < nums[j + 1]) {
                    pivot = j;
                    break;
                }
            }

            if (pivot == -1) {
                reverse(nums.begin(), nums.end());
                continue;
            }

            for (int k = n - 1; k > pivot; k--) {
                if (nums[k] > nums[pivot]) {
                    swap(nums[k], nums[pivot]);
                    break;
                }
            }
            reverse(nums.begin() + pivot + 1, nums.end());
        }

        return res;
    }
};