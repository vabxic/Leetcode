class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        const size_t k = s.size();
        long long  ans = 0;
        long long sum = 0;
        string temp = "";
        for (int i = 0 ; i < k ; ++i ){
            if (s[i] == '0')continue;
            else {
                sum += s[i] - '0';
                temp += s[i];
            }
        }
        if (temp.empty()) return 0;
        ans = stoll(temp)*sum;
        return ans ;
    }
};