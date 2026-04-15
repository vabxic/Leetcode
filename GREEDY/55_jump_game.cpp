#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool jumpGame(vector <int>&nums ){
    int n = nums.size();
    int maxReach = nums[0];
    for (int i = 0 ; i<n;i++ ){
        if (i>maxReach){
            return false;
        }    
        maxReach = max(maxReach,nums[i]+i);
    }return true ;
}
int main()
{
    vector<int>vec1 = {2,3,1,1,4};
    vector<int>vec2 = {3,2,1,0,4};
    cout<<jumpGame(vec1);
    cout<<jumpGame(vec2);
    return 0;
}
