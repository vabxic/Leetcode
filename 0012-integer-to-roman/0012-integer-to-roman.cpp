class Solution {
public:
    string intToRoman(int num) {
        static vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};
        string result = "";
        for (int i = 0; i < 13; ++i) {
            if (num == 0)
                break;

            int times = num / roman[i].first;
            while (times--) {
                result += roman[i].second;
            }
            num %= roman[i].first;
        }
        return result;
    }
};