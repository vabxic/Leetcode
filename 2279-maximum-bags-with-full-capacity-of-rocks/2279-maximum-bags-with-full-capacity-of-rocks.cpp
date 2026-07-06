class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        const size_t n = capacity.size();
        vector<int>rem(n);

        for(int i = 0; i < n; ++i){
            rem[i] = capacity[i] - rocks[i];
        }
        sort(rem.begin(),rem.end());
        int i = 0;

        while(i < n && additionalRocks >= rem[i]){
            additionalRocks -= rem[i];
            i++;
        }
        return i;
    }
};