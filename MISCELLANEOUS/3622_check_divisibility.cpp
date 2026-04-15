#include <iostream>
#include <vector>
#include<stdlib.h>
using namespace std;
bool checkDivisiblity(int num ){
    int sum = 0 , product = 1;
    int n =num;
    while(num>0){
       int remainder = num %10;
        sum += remainder;
        product *= remainder;
        num /= 10;
    }
   
    return ((sum != 0 && abs(n)%sum==0)&&(product != 0 && abs(n) % product==0));

    
    
}
int main()
{
    cout <<checkDivisiblity(99);
    
    return 0;
}
