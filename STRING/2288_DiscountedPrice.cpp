// Input: sentence = "there are $1 $2 and 5$ candies in the shop", discount = 50
// Output: "there are $0.50 $1.00 and 5$ candies in the shop"

#include <bits/stdc++.h>
using namespace std;
bool IsPrice(string sentence){
    string word;
        stringstream ss(sentence);
            while(ss >> word){
                if (word[0] != '$'){
                    return false;
                }
                for (int i = 1 ; i < word.size() ; i++){
                    if (!isdigit(word[i])){
                        return false;
                    }
                }
                if (word.size()==1){
                    return false;
                }
            }

        }
string discountPrices(string sentence, int discount) {
    stringstream ss(sentence);
    string word, result = "";

    while (ss >> word) {
        if (IsPrice(word)) {
            double paisa = stod(word.substr(1));
            paisa = paisa * (100 - discount) / 100.0;

            ostringstream out;
            out << fixed << setprecision(2) << paisa;
            // precising val

            word = "$" + out.str();
        }
        result += word + " ";
    }

    result.pop_back(); // remove last space
    return result;
}
int main()
{
    string str = "there are $1 $2 and 5$ candies in the shop";
    int discount = 50;
    cout<<discountPrices(str,discount);
    return 0;
}
