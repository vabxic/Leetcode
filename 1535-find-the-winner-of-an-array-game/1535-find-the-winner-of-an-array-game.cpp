class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int currWinner = arr[0];
        const size_t n = arr.size();
        int count = 0;

        for (int i = 1; i < n; ++i) {
            if (currWinner < arr[i]) {
                currWinner = arr[i];
                count = 1;
            } else {
                count++;
            }
            if (count == k) {
                return currWinner;
            }
        }
        return currWinner;
    }
};