#include <iostream>
#include <vector>
using namespace std;
vector <int> sortedSquare(vector<int> &nums){
    int n = nums.size();
    vector <int>result(n);
    int i = 0 , j = n-1 ;
    int  k = n-1;
    while(i<=j){//(k>=0)
        int a  = nums[i]*nums[i];
        int b  = nums[j]*nums[j];
        if (a>b){
            result[k]=a;
            i++;
        }
        else {
            result[k] = b;
            j--;
        }
        k--;

    }
    return result;
   


}
int main()
{
    vector<int> num = {-4,-1,0,3,10};
    vector<int>ans =sortedSquare(num);
    
    for (int i : ans ){
        cout<< i << " ";
    }
    return 0;
}
