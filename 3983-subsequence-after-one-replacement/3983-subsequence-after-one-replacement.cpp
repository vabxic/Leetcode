class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size() , m = t.size();

        vector<int>pre(m+1, 0);
        int i = 0;
        for (int j = 0 ; j < m ; ++j){
            pre[j+1] = pre[j];
            if ( i < n && s[i] == t[j]){
                i++;
                pre[j+1] = i;
            }
        }
        if (pre[m] == n)return true;

        vector<int>suf(m+1 , 0);
        i = n-1;
        for (int j = m-1; j >= 0; --j){
            suf[j] = suf[j+1];
            if (i >= 0 && s[i] == t[j]){
                i--;
                suf[j] = n- 1- i;
            }
        }
        for (int j = 0 ; j < m; ++j){
            if (pre[j] + suf[j+1] >= n-1) return true;
        }
        return false;
    }
};