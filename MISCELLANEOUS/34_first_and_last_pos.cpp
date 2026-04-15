// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
#include <bits/stdc++.h>
using namespace std;
int findfirst(vector<int>&nums, int target){    
    int n = nums.size();
    int st = 0 , end = n-1;
    int ans = -1;
        while(st<=end){
            int mid = st + (end - st)/2;
            if (nums[mid]==target){
                ans  = mid;
                end = mid-1;          //keep going left
            }
            else if (nums[mid]<target){
                st = mid+1;
            }
            else {
                end  = mid -1;
            }
        }
        return ans;
        }
int findlast(vector<int>&nums, int target){    
    int n = nums.size();
    int st = 0 , end = n-1;
    int ans = -1;
        while(st<=end){
            int mid = st + (end - st)/2;
            if (nums[mid]==target){
                ans  = mid;
                st = mid+1;          //keep going right
            }
            else if (nums[mid]<target){
                st = mid+1;
            }
            else {
                end  = mid -1;
            }
        }
        return ans;
        }
        vector<int> searchRange(vector<int>& nums, int target) {
            int first = findfirst(nums,target);
            if (first == -1) return {-1, -1};
            int last = findlast(nums,target);
            return {first,last};
        }
        
    
int main()
{
    vector<int> vec = {5,7,7,8,8,10};
    int target = 8;    

    vector<int> ans = searchRange(vec, target);

    cout << ans[0] << " " << ans[1];

    return 0;
}
