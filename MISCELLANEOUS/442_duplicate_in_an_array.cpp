    #include <bits/stdc++.h>
    using namespace std;
     vector<int> findDuplicates(vector<int>& nums) {
         vector<int>res;
        int n = nums.size();
        for(int i =  0 ; i<n ; i++){
            int num = nums[i];
            int MarkingIndex  = abs(num)-1;
    
            if (nums[MarkingIndex]>0){
                nums[MarkingIndex] *= -1;
            }
            else{
                res.push_back(MarkingIndex+1); 
            }
        }
        return res;
    }
    int main()
    {
        vector<int>nums = nums = {4,3,2,7,8,2,3,1};
        vector<int> vec = findDuplicates(nums);
        for (auto i : vec){
            cout<<i<<" "; 
        }
        return 0;
    }
    