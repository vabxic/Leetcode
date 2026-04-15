// Input: matrix = {1,3,5,7},{10,11,16,20},{23,30,34,60}, target = 3
// Output: true
#include <bits/stdc++.h>
using namespace std;
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0 ; i<m ;i++){
            for (int j = 0 ; j<n ; j++){
                if (matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
int main()
{
    vector<vector<int>>matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 60;
    cout<<searchMatrix(matrix,target);

    return 0;
}

