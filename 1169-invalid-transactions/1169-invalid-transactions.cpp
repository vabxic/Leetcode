class Solution {
public:
    struct T {
        string name, city, raw;
        int time, amt;
    };
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<T> v;
        for (string& s : transactions) {
            stringstream ss(s);
            string token;
            vector<string> parts;

            while (getline(ss, token, ',')) {
                parts.push_back(token);
            }
            v.push_back(
                {parts[0], parts[3], s, stoi(parts[1]), stoi(parts[2])});
        }
        int n = v.size();
        vector<bool> invalid(n, false);

        for (int i = 0; i < n; ++i) {
            if (v[i].amt > 1000) {
                invalid[i] = true;
            }

            for (int j = i + 1; j < n; ++j) {
                if (v[i].name == v[j].name &&
                    abs(v[i].time - v[j].time) <= 60 &&
                    v[i].city != v[j].city) {
                    invalid[i] = true;
                    invalid[j] = true;
                }
            }
        }
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            if (invalid[i])
                ans.push_back(v[i].raw);
        }
        return ans;
    }
};