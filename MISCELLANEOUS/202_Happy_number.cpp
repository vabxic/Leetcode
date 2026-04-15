#include <bits/stdc++.h>
using namespace std;
bool isHappy(int n) {
       
        while(n != 1 && n != 4){
            int sum = 0;
            while(n>0){
                int digit = n%10;
                sum += digit*digit;
                n = n/10;
            }
            n = sum;
        }
       
        if (n == 1){
            return true;
        }
        else{
            return false;
        }
    }
int main()
{
    int n1 = 19;
    int n2 = 2;
    cout<<isHappy(n1);
    cout<<isHappy(n2);
    return 0;
}
