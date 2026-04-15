// Input: num = 38
// Output: 2
// Explanation: The process is
// 38 --> 3 + 8 --> 11
// 11 --> 1 + 1 --> 2 
#include <bits/stdc++.h>
using namespace std;
    int addDigits(int num) {
        while (num >= 10){
            int sum = 0 ;
            while(num>0){
            sum += num % 10;
            num /= 10;
        } num = sum ;
    }return num;
        
    }
int main()
{
    cout<<addDigits(38);
    return 0;
}
