#include <bits/stdc++.h>
using namespace std;
 bool isPowerOfFour(int n) {
    if (n <= 0){
        return false;
    }
    if (n == 1){
        return true;
    }
        while(n % 4 == 0 ){
                n /= 4;
            }
            return n==1;
    }
int main()
{
    cout<<isPowerOfFour(16)<<endl;
    cout<<isPowerOfFour(0)<<endl;
    cout<<isPowerOfFour(9)<<endl;
    cout<<isPowerOfFour(256)<<endl;
    
    return 0;
}
