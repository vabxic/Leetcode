class Solution {
public:
    int digitRange(int x){
        int mn = 9 , mx = 0;
        while (x){
            int d = x % 10;
            mn = min(mn, d);
            mx = max(mx, d);
            x /= 10;
        }
        return mx - mn;
    }
    int maxDigitRange(vector<int>& nums) {
        int maxRange = -1;
        int sum = 0;

        for(int x : nums){
            int r = digitRange(x);
            if (r > maxRange){
                maxRange = r;
                sum =x;
            }else if (r == maxRange){
                sum += x;
            }
        
        }return sum;
    }
};