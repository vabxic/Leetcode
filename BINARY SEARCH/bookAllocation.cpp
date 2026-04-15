#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<int>arr,int n,int m,int mid){
    int student = 1, page = 0;
    for (int i =0;i<n;i++){
        if(arr[i]>mid){
            return false;
        }
        if(page + arr[i]<=mid){
            page += arr[i];
        }
        else {
           student++;
           page = arr[i]; 
        }
    }
    return student >m?false:true;

}
int allocateBooks(vector<int> &arr, int n, int m){
    if (m>n){
        return -1;
    }
    int st = 0 , sum =0;
    for (int i =0 ; i<n;i++){
        sum+=arr[i]; //range of possible answer
    }
    int ans = -1;
    int end = sum;
    while (st<=end){
        int mid = st+ (end-st)/2;
        if (isValid(arr,n,m,mid)){
            ans = mid;
            end = mid-1;        //left
        }
        else {    //right
            st = mid+1;
        }
    }
    return ans;
}
int main (){
    vector <int> arr = {2,1,3,4};
    int n = arr.size();
    int m = 2;
    cout<<allocateBooks(arr,n,m);
    return 0;
}