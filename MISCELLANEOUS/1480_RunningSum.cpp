#include <bits/stdc++.h>
using namespace std;
vector <int> RunningSum(vector<int>&nums){
     int n = nums.size();
        for (int i = 1 ; i<n ; i++){
            nums[i]=nums[i-1]+nums[i];
             }
        return nums;
}
int main()
{
    vector<int>vec = {1,2,3,4,5,6};
    RunningSum(vec);
    for(int i : vec){
        cout<<i<<" ";
    }
    return 0;
}
