#include <iostream>
#include <vector>
#include <string>
using namespace std;
int maxNumber(int num){
        string str = to_string(num);
        int n = str.length();
        int i = 0;
        while (i<n){
            if (str[i]=='6'){       // to optimize space complexity , take pass by reference
                str[i]='9';
               break;
                }
            i++;
            
        } num = stoi(str);
        return num;
}
int main()
{
    int num = 9669;
   cout << maxNumber(num);
    
    return 0;
}
//this is the first question i did without any help