#include <bits/stdc++.h>
using namespace std;
int strStr(string haystack, string needle) {
        if(haystack.find(needle)!= string::npos){
            return haystack.find(needle);
        }
        else {
            return -1;
        }
        
        
    }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<strStr("qleetcodeleet","leet");
    
    
    return 0;
}

