class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        const size_t n = s.size();

        vector<int>res;
        for (int i = 0; i < n ; i++){
            for (int j = i+2; j <= n ; j++){
                int current = stoi(s.substr(i , j-i));
                if (current >= low && current <= high){
                    res.emplace_back(current);
                } 
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};