// An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.
#include <bits/stdc++.h>
using namespace std;
bool isUgly(int n) {
       if (n <= 0){
        return false;
       }
       while (n % 2 == 0){n /= 2;}
       while (n % 3 == 0){n /= 3;}
       while (n % 5 == 0){n /= 5;}

       return n==1;
    }
int main()
{
    int n1 = 30;
    int n2= 14;
    cout<<isUgly(n1)<<endl;
    cout<<isUgly(n2)<<endl;
    return 0;
}
