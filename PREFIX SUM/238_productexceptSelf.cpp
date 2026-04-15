// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
#include<bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n);
        vector<int>right(n);
        left[0]= 1;
        right[n-1]= 1;
        for (int i = 1 ; i <n ; i++){
            left[i] = left[i-1]*nums[i-1];
        }
        for (int i = n-2; i>=0;i--){
            right[i] = right[i+1]*nums[i+1];
        }
        for (int i = 0 ; i < n ;i++){
            nums[i] = left[i] * right[i];
        }
        return nums;
}

int main (){
    vector<int>vec = {1,2,3,4};
    productExceptSelf(vec);
    for (int i :vec ){
        cout<<i<<" ";
    }
    return 0;
}