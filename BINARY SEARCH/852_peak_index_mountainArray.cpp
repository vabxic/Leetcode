#include <bits/stdc++.h>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr) {
        int st  = 0 , end  = arr.size()-1;
        while (st < end){
            int mid = st + (end-st)/2;
            if (arr[mid]<arr[mid+1]){
                 st = mid+1;
            }
            else end = mid;
            
        }return st;
    }
int main (){
    vector <int> vec = {1,2,3,6,8,12,7,5,2,0};
    cout<<peakIndexInMountainArray(vec);
}
