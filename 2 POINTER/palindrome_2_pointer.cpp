//121 is palindrome and -121 isnt
//solving this using 2 pointer
#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(int x){
        if (x<0){
            return false;
        }
    string str = to_string(x);
    int start = 0;
    int end = str.length()-1;
    while (start <end){
        if (str[start]!=str[end]){
            return false;
        }   
           start++;
            end--;
        
    }
    return true;
}
int main()
{
    int x = 121;
    cout <<isPalindrome(x);

    return 0;
}
