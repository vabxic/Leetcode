#include <bits/stdc++.h>
using namespace std;
 bool isPowerOfThree(int n) {
    if (n <= 0){
        return false;
    }
    if (n == 1){
        return true;
    }
        while(n % 3 == 0 ){
                n /= 3;
            }
            return n==1;
    }
int main()
{
    cout<<isPowerOfThree(27)<<endl;
    cout<<isPowerOfThree(0)<<endl;
    cout<<isPowerOfThree(9)<<endl;
    cout<<isPowerOfThree(121)<<endl;
    
    return 0;
}
