#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int RecursiveBinarySearch(vector <int>arr,int tar ,int st,int end){
  
    if (st<=end){
      int mid = st + (end -st)/2;
      if (tar > arr [mid]){
        return RecursiveBinarySearch(arr,tar,mid+1,end);
      }
      else if (tar<arr[mid]){
        return RecursiveBinarySearch(arr,tar,st,mid-1);
      }
      else 
      return mid;
    }
    return -1;
}
int main()
{
    vector <int> vec = {-1,0,2,3,5,7,8,9};
    int target =9 ;
    cout <<RecursiveBinarySearch(vec,target,0,vec.size()-1);
    return 0;
}
