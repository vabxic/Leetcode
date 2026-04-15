#include <bits/stdc++.h>
using namespace std;
   bool isPalindrome(string s) {
      string result;
      for (char c : s){
        if ((c>='a' && c <='z') || (c>='A' && c <='Z') ||
            (c >= '0' && c <= '9') ){
            result += tolower(c);
        }
      }
      
      int i = 0 ; int j = result.length()-1;
      while(i<j){
        if (result[i] != result[j]){
            return false;   
        }
        i++;
        j--;
      }
      return true;
        
    }
int main()
{
    string str = "A man, a plan, a canal: Panama";
    string str2 = "0P";
    cout <<isPalindrome(str)<<endl;
    cout <<isPalindrome(str2)<<endl;

    return 0;
}
