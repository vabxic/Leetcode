// Example 1:
// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.
// Example 2:

// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.

//refer to notes to understand cyclic sort
#include <bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();    
        int i = 0;
        
        while(i < n)
        {
            if(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            else {
                i++;}
        }
        for (int i = 0 ; i <n ; i++){
            if (nums[i] != i+1){
                return i+1;
            }
            
        }
        return n+1;
    }
int main()
{
    vector<int> vec = {3,4,-1,1};
    cout<<firstMissingPositive(vec);

    return 0;
}
