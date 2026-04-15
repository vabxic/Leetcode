// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
#include <bits/stdc++.h>
using namespace std;
 int trap(vector<int>& height) {
        int n = height.size();
        int left = 0 , right = n-1, ans = 0 , lmax = 0, rmax = 0;
        while(left<right){
            lmax = max(lmax,height[left]);
            rmax = max(rmax,height[right]);
            if (lmax<rmax){
                ans += (lmax - height[left]);
                left++;           
             }
                else {
            ans += (rmax - height[right]);
            right--;
        }
        }
        return ans;
        
    }
int main()
{
    
    vector<int> heights= {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(heights);

    return 0;   
}
