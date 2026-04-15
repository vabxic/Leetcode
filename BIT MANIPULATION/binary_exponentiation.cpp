#include <iostream>
#include <vector>
using namespace std;
double myPow(double x, int n) {
        long bf = n;
        double ans  = 1;
        if (n<0){
            bf =-bf;
            x = 1/x;
        }
        while (bf>0){
            if (bf % 2 == 1){
                ans *= x;
            }
            x*=x;
            bf /=2 ;
        }
        return ans ;
}
int main()
{
   
   cout <<myPow(4,-1);
    return 0;
}
