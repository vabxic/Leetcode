class Solution {
public:
    string stringHash(string s, int k) {
        const size_t n = s.size();
        string res = "";
        int sum = 0, count = 0;
        for (int i = 0 ; i < n ; i ++){
            sum += s[i]-'a';
            count ++;

            if (count == k){
                res += ('a' + (sum % 26));
                sum = 0;
                count = 0;
                
            }
        }return res;
    }
};