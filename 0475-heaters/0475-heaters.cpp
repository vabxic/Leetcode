class Solution {
public:
    bool isPossible(vector<int>& houses, vector<int>& heaters, int radius) {
        int i = 0;
        int j = 0;

        while (i < houses.size() && j < heaters.size()) {
            if (abs(houses[i] - heaters[j]) <= radius) {
                ++i; // house covered
            } else if (houses[i] < heaters[j]) {
                return false; // house is left of heater and not covered
            } else {
                ++j; // next heater
            }
        }

        return i == houses.size();
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int low = 0;
        int high = 1e9;

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(houses, heaters, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};