// Input: nums = [1,2,3]
// Output: [1,3,2]
#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int>& nums) {
        int n = nums.size(), pivot = -1;
        for (int i = n-2; i>= 0 ; i--){
            if (nums [i] < nums[i+1]){
                pivot = i ;
                break;
            }
            if (pivot == -1){
                reverse(nums.begin(),nums.end());
            }
        }
        for (int i = n-1 ; i>pivot ; i-- ){
            if (nums[i] > nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }
        reverse(nums.begin()+pivot+1, nums.end());

    }
int main()
{
    vector <int> vec = {1,2,3};
    nextPermutation(vec);
    for (int  i : vec){
        cout <<i <<" ";
    }
    return 0;
}
