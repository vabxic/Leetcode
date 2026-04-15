// Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
// Output: true
#include <bits/stdc++.h>
using namespace std;
 bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = target.size();
        if (m!=n){
            return false;
        }
        for (int i = 0 ; i<n ;i++){
            for (int j = i; j<mat[i].size(); j++){
                swap (mat[i][j], mat[j][i]);
            }
        }
        for (int i =0 ;i<n ; i++){
            reverse(mat.begin(),mat.end());
        }
        for (int i = 0 ; i<n ;i++){
            for (int j = i; j<mat[i].size(); j++){
                if (mat[i][j]==target[i][j]){
                    return true;
                }
                else{
                    false;
                }
            }
        }
    }
int main()
{
    vector<vector<int>> mat ={{0,1},{1,0}};
    vector<vector<int>> target ={{1,0},{0,1}};
    cout<<findRotation(mat,target);
    return 0;
}
//login not complete