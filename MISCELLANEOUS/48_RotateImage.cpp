// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
#include <bits/stdc++.h>
using namespace std;
 void rotate(vector<vector<int>>& matrix) {
         int n = matrix.size();
       for (int i = 0;i<matrix.size();i++){
        for(int j = i; j< matrix[i].size();j++){
            swap(matrix[i][j],matrix[j][i]);
        }
       }
       for (int i =0 ;i<n ; i++){
        reverse(matrix[i].begin(),matrix[i].end());
       }
       
    }
int main()
{
    vector<vector<int>>vec = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(vec);
    for (int i = 0 ;i<vec.size();i++){
        for (int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
    }
    return 0;
}
