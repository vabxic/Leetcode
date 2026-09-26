class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long first = 0;
        long long second = 0;

        for (int num : source)
            first += num;
        for (int num : target)
            second += num;

        return first == second;
    }
};