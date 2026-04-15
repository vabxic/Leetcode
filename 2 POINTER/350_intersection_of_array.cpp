#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
    vector<int>vec;
    int n  = nums1.size();
    int m  = nums2.size();
    int i=0;int j = 0;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    while (i<n && j<m){
        if ( nums1[i]==nums2[j]){
            vec.push_back(nums1[i]);
            i++;j++;
        }
        else if (nums1[i]<nums2[j]){
            i++;
        }
        else {
            j++;
        }
         
    } // use set if u want unique output
    return vec;
}
int main()
{
    vector<int>nums1 = {9,4,5,7,8,3,2,5};
    vector<int>nums2 = {1,5,8,6,5,0,6,9};
    vector<int>vec = intersect(nums1,nums2);
    for (int i : vec){
        cout <<i<<" ";
    }
    
    
    return 0;
}
