#include <iostream>
#include <vector>
using namespace std;
vector <int> twoSum(vector <int> & numbers,int target){
    vector<int>nums;
    int n = numbers.size();
    int i =0 , j = n-1;
    while(i<j){
        if (numbers[i]+numbers[j]>target){
            j--;
        }
        else if(numbers[i]+numbers[j]<target){
            i++;
        }
        else {
            nums.push_back(i);
            nums.push_back(j);
            break;
        }
    }
    return nums;
}
int main()
{
    vector<int> vec = {2,7,11,15};
    int target = 26 ;
    vector <int> num = twoSum(vec,target);
    cout<<num[0]<<" "<<num[1];
    
    return 0;
}
