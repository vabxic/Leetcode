// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows) {
        vector<vector<int>> generate(numRows);
        
        for (int i = 0 ; i<numRows ; i++){
            generate[i].resize(i+1);
            for(int j = 0 ; j<=i;j++){
                if (j == 0 || j == i){
                    generate[i][j] = 1;
                }
                else {
                    generate[i][j] = generate[i-1][j-1] + generate[i-1][j];
                }
               

            }
        }
        return generate;
    }

int main(){
    int n ;
    cout <<"Enter the number of rows in pascals traingle: ";
    cin >> n ;
    vector<vector<int>> num = generate(n);
    for (const vector<int>& row : num) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    

    return 0;
}
