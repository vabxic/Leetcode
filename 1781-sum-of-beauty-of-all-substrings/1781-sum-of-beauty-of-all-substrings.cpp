class Solution {
public:
    int beautySum(string s) {

        size_t n = s.size();
        int sumOfBeauty = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {

                freq[s[j] - 'a']++;
                int maxi = *max_element(freq.begin(), freq.end());

                int mini = INT_MAX;
                for (int x : freq) {
                    if (x > 0)
                        mini = min(mini, x);
                }

                sumOfBeauty += (maxi - mini);
            }
        }
        return sumOfBeauty;
    }
};