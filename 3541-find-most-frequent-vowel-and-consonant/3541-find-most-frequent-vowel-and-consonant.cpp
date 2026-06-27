class Solution {
public:
    int maxFreqSum(string s) {
        const size_t n = s.size();
        string vowel = "aeiou";
        unordered_map<char, int> mp;

        int maxVowel = 0, maxCons = 0;
        for (char ch : s) {
            mp[ch]++;
        }
        for (auto& [ch, freq] : mp) {
            if (vowel.find(ch) != string::npos)
                maxVowel = max(maxVowel, freq);
            else
                maxCons = max(maxCons, freq);
        }
        return maxVowel + maxCons;
    }
};