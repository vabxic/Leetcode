// Input: letters = ["c","f","j"], target = "a"
// Output: "c"
#include <bits/stdc++.h>
using namespace std;
char nextGreatestLetter(vector<char>& letters, char target) {
    int st = 0, end = letters.size() - 1;
    char ans = letters[0]; 

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (letters[mid] > target) {
            ans = letters[mid];
            end = mid - 1;   
        } else {
            st = mid + 1;   
        }
    }
    return ans;
}
int main()
{
    vector<char>  letters = {'c','f','j'};
    char target = 'a';
    cout<< nextGreatestLetter(letters,target);
    return 0;
}
