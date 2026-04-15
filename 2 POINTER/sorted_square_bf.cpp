#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Input: nums = [-4,-1,0,3,10]
//  Output: [0,1,9,16,100]
 vector<int> sortedSquares(vector<int>& nums) {
        vector<int> vec ;
        for(int i : nums){
           vec.push_back(i*i);
        
        }
        sort(vec.begin(),vec.end());
        // for (int i = 0 ;i<nums.size();i++){
        //     vec.push_back(nums[i]*nums[i]);
        // }
        return vec;
    }
int main()
{
    vector<int> num = {-4,-1,0,3,10};
    vector<int>ans =sortedSquares(num);
    
    for (int i : ans ){
        cout<< i << " ";
    }
    return 0;
}
