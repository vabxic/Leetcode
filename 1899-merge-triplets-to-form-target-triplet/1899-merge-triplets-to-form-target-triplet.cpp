class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        const size_t n = triplets.size();
        vector<int>maxVal = {0,0,0};

        for (auto t : triplets){
            if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]){
                maxVal[0] = max(maxVal[0],t[0]);
                maxVal[1] = max(maxVal[1],t[1]);
                maxVal[2] = max(maxVal[2],t[2]);
            }
            if (maxVal == target)return true;
        }
        return false;
    }
};