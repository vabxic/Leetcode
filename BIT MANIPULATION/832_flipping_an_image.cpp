// Example 1:

// Input: image = [[1,1,0],[1,0,1],[0,0,0]]
//  First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
// Output: [[1,0,0],[0,1,0],[1,1,1]]

// Example 2:

// Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
//  First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
// Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]

#include <bits/stdc++.h>
using namespace std;
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
       for (int i = 0; i < image.size(); i++) {
         int left = 0, right = image[i].size() - 1;

         while (left < right) {
        swap(image[i][left], image[i][right]);
        left++;
        right--;
    }
        }
        for (int i = 0;i<image.size();i++){
            for (int j =0 ;j<image[i].size();j++){
              image[i][j] ^= 1;
            }
        }
        return image;
       
    }
int main()
{   vector<vector<int>>image ={{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    int n = image.size();
        flipAndInvertImage(image);
        for (int i = 0 ; i<image.size();i++){
            for (int j =0 ; j<image[i].size(); j++){
                cout<<image[i][j]<<" ";
            }
        }
    return 0;
}
