/*
Approach 1 52 ms
class Solution {
    
public:
    int Atmost(string s,int k){
        const size_t n = s.size();
        int left = 0 , count = 0;
        unordered_map<char,int>mp;

        for (unsigned right = 0 ; right < n ; right++){
            mp[s[right]]++;
            while (mp.size() > k){
                mp[s[left]]--;
                if (mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
    int numberOfSubstrings(string s) {
        return Atmost(s, 3) - Atmost(s, 2);
    }
};*/


/*approach 2   15 ms
class Solution {
public:
    int numberOfSubstrings(string s) {

        int left = 0;
        int count = 0;
        unordered_map<char,int> mp;
        for (int right = 0 ; right < s.size() ; right++){
            mp[s[right]]++;
            while (mp['a'] > 0 &&
                   mp['b'] > 0 &&
                   mp['c'] > 0){

                count += s.size() - right;

                mp[s[left]]--;
                left++;
            }
        }
        return count;
    }
};
*/
// apporach 3 7 ms
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, 0);
        int res = 0;
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'a']++;
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                res += (s.length() - right);
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return res;
    }
};