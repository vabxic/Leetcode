#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxArea(vector<int> &height){
    int n = height.size();
    int left = 0,right = n-1,maxWater= 0 ;
    while(left<right){
        int width = right-left;
        int h = min(height[left],height[right]);
        int currWater = width*h;
        maxWater = max(currWater,maxWater);
        height[left]<height[right]?left++:right--;

    }   return maxWater;
    
}
int main()
{
    vector<int>vec = {1,8,6,2,5,4,8,3,7};
    cout <<maxArea(vec);
    return 0;
}
