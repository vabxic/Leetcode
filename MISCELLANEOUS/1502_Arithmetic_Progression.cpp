#include <bits/stdc++.h>
using namespace std;
bool canMakeArithmeticProgression(vector<int>& arr) {
        int n  = arr.size();
        sort(arr.begin(),arr.end());
        int commonDifference = arr[1]-arr[0];
        for (int i = 2 ; i<n;i++){
            if (arr[i]-arr[i-1] != commonDifference){
                return false;
            }
            
        }
        return true;
    }
int main()
{
    vector <int> vec = {1,10,10,10,19};
  
    cout<< canMakeArithmeticProgression(vec);
    return 0;
}
