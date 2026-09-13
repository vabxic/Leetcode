class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> freqMap;
        unordered_map<int, int> indexMap;
        unordered_map<int, int> distMap;

        unordered_set<int> set;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            freqMap[num]++;

            if (freqMap[num] == 2) {
                distMap[num] = i - indexMap[num];
            }

            if (freqMap[num] > 2) {
                int lastIndex = indexMap[num];

                if (i - lastIndex != distMap[num])
                    set.insert(num);
            }

            indexMap[num] = i;
        }

        int cnt = 0;

        for (auto& it : freqMap) {
            int key = it.first;
            int value = it.second;

            if (value < 3)
                continue;

            ++cnt;
        }

        return cnt - set.size();
    }
};