#include <iostream>
#include <vector>
#include <algorithm>
//tc - O(log n) sc - O(n)
using namespace std;
int binarySearch(vector<int>nums, int target){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int st= 0,end= n-1;
        while(st<=end){
            int mid = st+  (end-st)/2;
            if (target>nums[mid]){
                st = mid+1;
            }
            else if (target<nums[mid]){
                end = mid -1;
            }
            else {
                return mid;
            }
        }return -1;
}
int main()
{
    vector <int>vec = {4,-1,9,3,2,7,5,0,12,16};
    int tar = 2;
    cout<<binarySearch(vec,tar);
    return 0;
}
