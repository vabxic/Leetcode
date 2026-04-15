// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4]
#include <bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    for (int i = n-1 ; i>=0 ; i--){
        if (digits[n-1]<9){
            digits[n-1]++;
            return digits;
        }
        else {
            digits[i]=0;
        }
    }
    digits.insert(digits.begin(),1);
    return digits;
        

    }
int main()
{
    vector <int>digits = {1,2,3};
    plusOne(digits);
    return 0;
}
