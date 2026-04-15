#include <bits/stdc++.h>
using namespace std;

    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 0 ; i < n ; i++){
            for (int j =0 ; j <n ; j++){
                if  ((nums[i] == nums[j]) && (i<j)){
                    count++;
                }
                else {
                    continue;
                }
            }
        }
        return count;
    }
int main()
{
    vector<int>vec= {1,2,3,1,1,3};
    cout<<numIdenticalPairs(vec);
    return 0;
}
