class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(), piles.rend());

        int res = 0;
        int l = 0, r = piles.size() - 1;

        while (l < r) {
            l++;                
            res += piles[l++];  
            r--;              
        }

        return res;
    }
};