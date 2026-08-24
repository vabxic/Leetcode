class Solution {
public:
    bool isPossible(vector<int>& arr, int m, int k, int days) {
        int bouquet = 0, flower = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= days) {
                flower++;
                if (flower == k) {
                    bouquet++;
                    flower = 0;
                }
            } else {
                flower = 0;
            }
        }
        return bouquet >= m;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = 0;
        if ((long long)m * k > arr.size())
            return -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};