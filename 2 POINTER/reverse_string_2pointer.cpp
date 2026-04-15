#include <iostream>
#include <vector>
#include <string>
using namespace std;
void reverseString(vector<char> &s){
      int i = 0 ,  j = s.size()-1;
      while(i<j){
        swap(s[i],s[j]);
        i++;
        j--;
      }
}
int main()
{
    vector<char> vec ={'H','E','L','L','O'};
    reverseString(vec);
    for(char c : vec){
        cout << c << " ";
    }
    return 0;
}
