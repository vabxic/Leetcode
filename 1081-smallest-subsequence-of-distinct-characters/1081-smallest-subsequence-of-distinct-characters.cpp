using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")
static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int>lastIdx(26);
        vector<bool>seen(26,false);

        for(int i = 0 ; i < n ; i++){
            char ch  = s[i];
            lastIdx[ch - 'a'] = i;
        }

        string res = "";
        for(int i = 0 ; i < n ; i++){
            char ch = s[i];
            if(seen[ch - 'a'])continue;

            while(res.size() > 0 && res.back() > ch && lastIdx [res.back() - 'a'] > i){
                seen[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(ch);
            seen[ch - 'a'] = true;
        }
        return res;
        

    }
};