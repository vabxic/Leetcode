// Input: matrix = {1,3,5,7},{10,11,16,20},{23,30,34,60}, target = 3
// Output: true
#include <bits/stdc++.h>
using namespace std;
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int st = 0, end = m*n-1;
        while (st<=end){
            int mid = st + (end-st)/2;
            int row = mid/n;   // this is to convert 2D into 1D array
            int col = mid%n;
            if (matrix[row][col]== target){
                return true;
            }
            else if (matrix[row][col] < target){
                st = mid +1 ;
            }
            else {
                end = mid-1;
            }
        }
        return false;
    }
int main()
{
    vector<vector<int>>matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 222;
    cout<<searchMatrix(matrix,target);

    return 0;
}

