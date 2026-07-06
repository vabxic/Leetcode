class Solution {
public:
    int getF(string& s) {
        int a[26] = {0};
        for (char c : s)
            a[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (a[i] != 0)
            return a[i];
        }
        return 0;
    }

    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
        int n = q.size();
        int m = w.size();

        vector<int> result;
        vector<int> queriesFreq(n);
        vector<int> wordFreq(m);

        for (int i = 0; i < n; i++)
            queriesFreq[i] = getF(q[i]);

        for (int i = 0; i < m; i++)
            wordFreq[i] = getF(w[i]);

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (wordFreq[j] > queriesFreq[i])
                    cnt++;
            }
            result.push_back(cnt);
        }

        return result;
    }
};