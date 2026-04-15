// Input: heights = [1,1,4,2,1,3]
// Output: 3
#include <bits/stdc++.h>
using namespace std;
 int heightChecker(vector<int>& heights) {
        int count = 0;
        vector <int>vec;
        for (int i =0 ; i < heights.size(); i++){
            vec.push_back(heights[i]);
        }
        sort(heights.begin(),heights.end());
       for (int i = 0 ; i< heights.size(); i++){
        if (heights[i]!=vec[i]){
            count++;
        }
        else {
            continue;
        }
       }
       return count;
    }
int main()
{
    vector<int> vec = {1,2,3,4,5};
    cout<<heightChecker(vec);

    return 0;
}
