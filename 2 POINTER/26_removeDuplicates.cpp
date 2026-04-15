#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>&nums){
    int n = nums.size(),i = 0, j = i+1,count = 1;
    while(j<n){
        if (nums[j]!=nums[i]){
            i++;
            nums[i]=nums[j];
            count++;

        }
        j++;
    }
    return count;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int>nums = {0,0,1,1,1,2,2,3,3,4};
    cout<<removeDuplicates(nums);
    return 0;
}

