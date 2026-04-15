#include <bits/stdc++.h>
using namespace std;
 bool isPowerOfTwo(int n) {
    if ((n <= 0) || (n%2 != 0)){
        return false;
    }
        while(n % 2 == 0 ){
                n /= 2;
            }
            return n==1;
    }
int main()
{
    cout<<isPowerOfTwo(32)<<endl;
    cout<<isPowerOfTwo(0)<<endl;
    cout<<isPowerOfTwo(30);
    
    return 0;
}
